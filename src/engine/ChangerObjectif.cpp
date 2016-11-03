#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace state;
using namespace engine;

void ChangerObjectif::run(Etat* e, std::vector<int> params, sf::Time t) {
	Personnage & p = e->getRefPersonnage(params[0]);
	p.setEnDeplacement(true);
	std::cout << "Changer Objectif :: run ( x : " << params[1] << " , y : " << params[2] << ") " << std::endl;
	p.setXobj(params[1]);
	p.setYobj(params[2]);
}

