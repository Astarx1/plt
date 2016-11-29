#include "../engine.h"

#include <iostream>
#include <chrono>
#include <thread>

#define TRACE_LC 1

using namespace engine;
using namespace std;

void ListeCommandes::Ajouter (Commande cmd){
	mut_buf.lock();
	commandes_buf.push_back(cmd); // Il faudrait rajouter un controle de la taille du buffer !
	mut_buf.unlock();
}

void ListeCommandes::ToutExecuter (){
	while (true) {
		mut_buf.lock();
		commandes = commandes_buf;
		commandes_buf.clear();
		mut_buf.unlock();

		if (commandes.size() > 0){
			unsigned int i;
			for (i=0;i<commandes.size();i++){
				(commandes[i]).run();
				if (commandes[i].getType() == "cm" || commandes[i].getType() == "ec") {
					commandes.clear();
					#if TRACE_LC == 1
					std:: cout << "ListeCommandes::ToutExecuter : On a clear les commandes " << std::endl;
					#endif
					//std::this_thread::sleep_for(std::chrono::milliseconds(5));
					break;
				}
			}
			commandes.clear();
		}
	}
}

