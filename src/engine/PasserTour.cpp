#include "../engine.h"
#include "../state.h"

using namespace engine;
using namespace state;

void PasserTour::run (Etat* e, std::vector<int> params, sf::Time t) {
  	Combat & c = e->getRefCombat();	
  	c.tourSuivant(t);
}

