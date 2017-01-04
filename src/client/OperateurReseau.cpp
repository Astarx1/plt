#include "OperateurReseau.h"

#include <json/json.h>

using namespace client;

void OperateurReseau::th_in () {

}

void OperateurReseau::th_out () {        
	sf::Packet packetSend;
	std::string cmd_json;

	mut_out.lock();
	in_th_buf = out_cmd_list;

	//mut_out.unlock(); Je le commente pour eviter l'overflow de commande. Si ça va assez vite, on peut reconsiderer le fait de l'enlever
	for (auto d : in_th_buf) {
		cmd_json = d.serialize(epoque_locale);
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