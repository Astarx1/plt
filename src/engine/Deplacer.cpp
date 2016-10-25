#include "../engine.h"
#include "../state.h"

using namespace engine;
using namespace state;

#define ECART 2

int abs (int a) { return a >= 0 ? a : -a; }
int signe (int a) { return a >= 0 ? 1 : -1; }


/* Params :
0 -> id du personnage 
Besoin : clock ! > Changer le constructeur
*/

void Deplacer::run(Etat* e, std::vector<int> params) {
    Personnage & p = e->getRefPersonnage(params[0]);
  	if (p.getEnDeplacement()) {
      	// Appel à la regle pour obtenir la vitesse du personnage !
      	int speed = 1;
      
      	if (abs(p.getX()-p.getXobj()) > ECART) { 
		// Quand j'aurais une clock correcte
        	// p.setX(p.getX() + signe(p.getXobj()-p.getX()) * speed * (cl.getElapsed().getAsMillisecond()-p.getTimer().getAsMillisecond())
        }
     	else if (abs(p.getY()-p.getYobj()) > ECART) {
		// Quand j'aurais une clock correcte
        	// p.setY(p.getY() + signe(p.getYobj()-p.getY()) * speed * (cl.getElapsed().getAsMillisecond()-p.getTimer().getAsMillisecond())
      	}
    }
}
