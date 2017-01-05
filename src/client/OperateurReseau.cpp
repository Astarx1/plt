#include "OperateurReseau.h"
#include "json/json.h"
#include <iostream>

#define TRACE_OPRESEAU 1

using namespace client;

void OperateurReseau::run() {
	sf::Http::Request request;
	std::vector<sf::Http::Response> responses;
	std::string cmd_json;
	sf::Http::Response last_response;
	Json::Reader jsonReader;
	Json::Value jsonObject_in, jsonObject_array_in;
	int epoque_serveur = 0;
	std::vector<int> params_cmd;
	bool loop_in;

	while(active) {
		// On récupère les données
		epoque_serveur = epoque_locale;
		mut_in.lock();
		loop_in = true;
		while (loop_in) {
			request.setMethod(sf::Http::Request::Get);
			request.setUri("/commande/" + epoque_locale);
			request.setHttpVersion(1, 1); // HTTP 1.1 
			last_response = http.sendRequest(request);

			if (last_response.getStatus() != 200) {
				epoque_locale++;
				loop_in = false;
			}
			else {
				jsonObject_in = last_response.getBody();
				jsonReader.parse(cmd_json,jsonObject_in);

				epoque_locale = jsonObject_in["epoque"].asInt();

				params_cmd.clear();
				int i = 0;
				while ((jsonObject_array_in = jsonObject_in["params"].get(i, Json::nullValue)) != Json::nullValue) {
					params_cmd.push_back(jsonObject_array_in.asInt());
				}

				// Probleme : time n'est pas defini 
				out_cmd_list.push_back(engine::Commande(e,jsonObject_in["type"].asString(), sf::Time(), params_cmd, 0));
			}
		} 
		mut_in.unlock();

		// On décharge les commande en local
		mut_out.lock();
		in_th_buf = out_cmd_list;

		//mut_out.unlock(); Je le commente pour eviter l'overflow de commande. Si ça va assez vite, on peut reconsiderer le fait de l'enlever
		
		for (auto d : in_th_buf) {
			cmd_json = d.serialize(epoque_locale);

			request.setMethod(sf::Http::Request::Put);
			request.setUri("/commande/");
			request.setHttpVersion(1, 1); // HTTP 1.1
			request.setField("Content-Type", "json/json");
			request.setBody(cmd_json);

			last_response = http.sendRequest(request);
		}
		mut_out.unlock();
		
		jsonObject_in = last_response.getBody();
		jsonReader.parse(cmd_json,jsonObject_in);

		epoque_locale = jsonObject_in["epoque"].asInt();
	}
}

std::vector<engine::Commande> OperateurReseau::getCmd () {
	std::vector<engine::Commande> tmp;
	mut_in.lock();
	tmp = in_cmd_list;
	in_cmd_list.clear();
	mut_in.unlock();

	return tmp;
}

void OperateurReseau::putCmd (engine::Commande cmd) {
	mut_out.lock();
	out_cmd_list.push_back(cmd);
	mut_out.unlock();
}

OperateurReseau::OperateurReseau(state::Etat * ne) : http("127.0.0.1") {
	e = ne;
}