#include "Rendu.h"

using namespace render;
using namespace state;

void Rendu::run (Etat* e, sf::RenderWindow& sw, sf::Clock& cl) {
	rg.dessin(sw, e);
	rp.dessin(sw, e, 0, cl);
}

Rendu::Rendu () {  
}
