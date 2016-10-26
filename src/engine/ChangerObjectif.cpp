#include "../engine.h"
#include "../state.h"

using namespace state;
using namespace engine;

void ChangerObjectif::run(Etat* e, std::vector<int> params, sf::Time t) {
    Personnage & p = e->getRefPersonnage(params[0]);
    p.setXobj(params[1]);
    p.setXobj(params[2]);
}

