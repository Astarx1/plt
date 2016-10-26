#include "../engine.h"
#include "../state.h"

using namespace engine;
using namespace state;

/* Pas de params */

void QuitterCombat::run(Etat* e, std::vector<int> params,sf::Time t){
 	int ma = e->getMapActuel(); 
 	std::vector<int> param;
  	param.push_back(ma);
  
        ChangerMap cm;
  	cm.run (e, param,t); 
  
  	e->setEnCombat(false);
}
