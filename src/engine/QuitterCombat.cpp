#include "../engine.h"
#include "../state.h"

using namespace engine;
using namespace state;

/* Pas de params */

void QuitterCombat::run(Etat* e, std::vector<int> params){
 	int ma = e->getMapActuel(); 
 	std::vector<int> param;
  	param.push_back(ma);
  
    ChangerMap t;
  	t.run (e, param); 
  
  	e->setEnCombat(false);
}
