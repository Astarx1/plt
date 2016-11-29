#include "../engine.h"
#include "../state.h"

#include <iostream>

#define TRACE_CO 1

using namespace state;
using namespace engine;

void ChangerObjectif::run(Etat* e, std::vector<int> params, sf::Time t) {
	Personnage & p = e->getRefPersonnage(params[0]);
	if (params[1] != -1 && params[2] != -1) {
		if (e->getMapActuel() == 1) {
			if (params[1] >= 20) 
				params[1] = 19;
			if (params[1] <= 0) 
				params[1] = 1;
			if (params[2] >= 16) 
				params[2] = 15;
			if (params[2] <= 5) 
				params[2] = 6;
		}
		else if (e->getMapActuel() == 4) {
			if (params[1] >= 17) 
				params[1] = 16;
			if (params[1] <= 4) 
				params[1] = 5;
			if (params[2] >= 14) 
				params[2] = 13;
			if (params[2] <= 2) 
				params[1] = 3;
		}

		p.setEnDeplacement(true);
		sf::Vector2f r = e->getCoordTile(params[1], params[2]);
		#if TRACE_CO==1
			std::cout << "Changer Objectif :: run ( x : " << params[1] << " - " << r.x << " , y : " << params[2] << " - " << r.y << " ) " << std::endl;
		#endif
		p.setXobj(r.x);
		p.setYobj(r.y);
		
		e->notifyObserver('p',t);
	}
}

