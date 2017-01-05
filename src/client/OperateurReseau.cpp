#include "OperateurReseau.h"
#include "json/json.h"
#include <iostream>

#define TRACE_OPRESEAU 1

using namespace client;

void OperateurReseau::th_in () {	
	sf::Packet packetIn;
	std::string cmd_json;
	Json::Reader jsonReader;
	Json::Value jsonObject_in;

	cmd_json = sender.receive(packetIn);
	/* Il faudrait parser la string pour ne garder que la partie à partir de { */
	if (jsonReader.parse(cmd_json,jsonObject_in)) {
		;
	}
	#if TRACE_OPRESEAU == 1
	else {
		std::cout << "OperateurReseau::th_in : Erreur paquet" << std::endl;
	}
	#endif
}

void OperateurReseau::th_out () {        
	sf::Packet packetSend;
	std::string cmd_json;

	mut_out.lock();
	in_th_buf = out_cmd_list;

	//mut_out.unlock(); Je le commente pour eviter l'overflow de commande. Si ça va assez vite, on peut reconsiderer le fait de l'enlever
	for (auto d : in_th_buf) {
		cmd_json = "PUT /commande/ HTTP/1.1\n\n";
		cmd_json += d.serialize(epoque_locale);
		packetSend << cmd_json;
		sender.send(packetSend);
	}

	mut_out.unlock();
}

void OperateurReseau::run() {
	while(active) {
		th_in();
		th_out();
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

OperateurReseau::OperateurReseau(state::Etat * ne) {
	e = ne;
}