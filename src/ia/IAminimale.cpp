#include <vector>
#include "../ia.h"
#include "../engine.h"
#include "../state.h"
#include <iostream>

#define TRACE_IAMIN 0

#define MVTPROBABILITY 10000

using namespace state;
using namespace ia;
using namespace engine;

IAminimale::IAminimale(state::Etat* etat){
	this->etat = etat;
}

IAminimale::~IAminimale(){

}

Commande IAminimale::exec_cmd(int id, sf::Time time){
	//(etat->accesPerso())->lock();
	std::lock_guard<std::mutex> lock(*(etat->accesPerso()));
	Personnage* ptr;
	std::vector<int> params;
	params.resize(2);
	if (id < etat->getPersoSize()) {
		ptr = &(etat->getRefPersonnage(id));
	}
	else {
		std::cerr << "[Catched] IAminimale::exec_cmd : Out of Range error" << std::endl;
		params[0] = -1;
		params[1] = -1;
		Commande c(etat, "d" ,time,params,id);
		return c;
	}
	Personnage& perso = *ptr;
	
	if (true) {
		if(!perso.getEnDeplacement()){
			int a = rand() % MVTPROBABILITY;
			if (a != 0) {
				#if TRACE_IAMIN==1
					std::cout << "IAminimale::exec_cmd (" << id << ") : On ne se deplace pas, et on choisit de ne pas se deplacer : rand (" << a << ")" << std::endl;
				#endif
				params[0] = -1;
				params[1] = -1;
			}
			else {
				params[0]= rand()%20 +1;
				params[1]= rand()%12 +1;

				#if TRACE_IAMIN==1
					std::cout << "IAminimale::exec_cmd (" << id << ") : On ne se deplace pas, et on choisit de se deplacer : X (" << params[0] << ") Y (" << params[1] << ")" << std::endl;
				#endif
			}
		}
		else { 
			#if TRACE_IAMIN==1
				std::cout << "IAminimale::exec_cmd (" << id << ") : On se deplace ... on attend" << std::endl;
			#endif
			sf::Vector2f obj = etat->getGrilleCoord(perso.getXobj(), perso.getYobj());
			params[0]= obj.x;
			params[1]= obj.y;		
		}
	}
	Commande c(etat, "d" ,time,params,id);
	return c;
	//(etat->accesPerso())->unlock();
}
