#include <vector>
#include "../ia.h"
#include "../engine.h"
#include "../state.h"

#define MVTPROBABILITY 10

using namespace state;
using namespace ia;
using namespace engine;

IAminimale::IAminimale(state::Etat* etat){
    this->etat = etat;
}

IAminimale::~IAminimale(){

}

Commande IAminimale::exec_cmd(int id, sf::Time time){
    Personnage& perso = this->etat->getRefPersonnage(id);
    
    std::vector<int> params;
    params.resize(2);
	if (etat->getEnCombat()) {
	    if(!perso.getEnDeplacement()){
		int a = rand() % MVTPROBABILITY;
		if (a != 0) {
			params[0] = -1;
			params[1] = -1;
		}
		else {
			params[0]= rand()%20 +1;
			params[1]= rand()%12 +1;
		}
	    }
	    else{
		sf::Vector2f obj = etat->getGrilleCoord(perso.getXobj(), perso.getYobj());
		params[0]= obj.x;
		params[1]= obj.y;
		
	    }
	}
    Commande c(etat, "d" ,time,params,id);
    return c;
}
