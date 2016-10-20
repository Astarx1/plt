#include "Rendu.h"
#include <iostream>

using namespace render;
using namespace state;

void Rendu::run (Etat* e, sf::RenderWindow& sw, sf::Clock& cl, sf::RenderStates rs) {
	rg.dessin(sw, e);
	rp.dessin(sw, e, 0, cl, rs);
}

Rendu::Rendu () {  
}
