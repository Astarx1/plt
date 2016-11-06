#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace engine;
using namespace state;

#define ECART 4

int abs (int a) { return a >= 0 ? a : -a; }
int signe (int a) { return a >= 0 ? 1 : -1; }


/* Params :
0 -> id du personnage 
Besoin : clock ! > Changer le constructeur
*/

void Deplacer::run(Etat* e, std::vector<int> params,sf::Time t) {
	Personnage & p = e->getRefPersonnage(params[0]);
	if (p.getEnDeplacement()) { 
	      	// Appel à la regle pour obtenir la vitesse du personnage !
	      	int speed = 0.4;
	      
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
			p.setEnDeplacement(false);
		}
	}
}
