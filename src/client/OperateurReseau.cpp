#include "OperateurReseau.h"

using namespace client;

void OperateurReseau::th_in () {

}
void OperateurReseau::th_out () {

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