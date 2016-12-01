#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace engine;
using namespace state;

#define ECART 2

#define DEPLACER_CERR_ACTIVE 1

int abs (int a) { return a >= 0 ? a : -a; }
int signe (int a) { return a >= 0 ? 1 : -1; }


/* Params :
0 -> id du personnage 
Besoin : clock ! > Changer le constructeur
*/

void Deplacer::run(Etat* e, std::vector<int> params,sf::Time t) {
	std::lock_guard<std::mutex> lock(*(e->accesPerso()));
	Personnage * ptr;
	if (params[0] < e->getPersoSize()) {
		ptr = &(e->getRefPersonnage(params[0]));
	}
	else {
		#if DEPLACER_CERR_ACTIVE==1
		std::cerr << "[Catched] Deplacer::run : Out of Range error" << std::endl;
		#endif
		return ;
	}
	Personnage& p = *ptr;
	if (p.getEnDeplacement()) { 
		// Appel à la regle pour obtenir la vitesse du personnage !
		int speed = 0.3;
	  
		if (abs(p.getX()-p.getXobj()) > ECART) {   
			int s = signe(p.getXobj()-p.getX());
			if (s == 1)
				p.setDirection(Direction(OUEST));
			else
				p.setDirection(Direction(EST));

			p.setX(p.getX() + s * speed * abs (t.asMilliseconds()-p.getTimer().asMilliseconds())+signe(p.getXobj()-p.getX()));
		}
		else if (abs(p.getY()-p.getYobj()) > ECART) {
			int s = signe(p.getYobj()-p.getY());
			if (s == 1)
				p.setDirection(Direction(SUD));
			else
				p.setDirection(Direction(NORD));
			
			p.setY(p.getY() + s * speed * abs (t.asMilliseconds()-p.getTimer().asMilliseconds())+signe(p.getYobj()-p.getY()));
		}
		else {
			p.setY(p.getYobj());
			p.setX(p.getXobj());
			p.setEnDeplacement(false);
		}
		
		e->notifyObserver('p',t);
	}
}
