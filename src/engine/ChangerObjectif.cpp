#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace state;
using namespace engine;

void ChangerObjectif::run(Etat* e, std::vector<int> params, sf::Time t) {
	Personnage & p = e->getRefPersonnage(params[0]);
	p.setEnDeplacement(true);
	sf::Vector2f r = e->getCoordTile(params[1], params[2]);
	std::cout << "Changer Objectif :: run ( x : " << params[1] << " - " << r.x << " , y : " << params[2] << " - " << r.y << " ) " << std::endl;
	p.setXobj(r.x);
	p.setYobj(r.y);
}

