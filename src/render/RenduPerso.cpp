#include "RenduPerso.h"

using namespace render;
using namespace state;

void RenduPerso::dessin (sf::RenderWindow& w, state::Etat* e, int id){
	Personnage& p = (e->getRefPersonnage(id));
	int tmpDeplacement = p.getTimer();
	bool enDeplacement = p.getEnDeplacement();
	Direction dir = p.getDirection();	
}

RenduPerso::RenduPerso () {
}

RenduPerso::~RenduPerso () {
}