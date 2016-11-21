
/* 
Besoin attribut/constructeur : 
Params :
0 -> id du personnage
1 -> nouveau xObj
2 -> nouveau yObj
*/

#include "../engine.h"
#include "../state.h"
#include <vector>

using namespace engine;
using namespace state;

void EntrerCombat::run(Etat* e, std::vector<int> params,sf::Time t) {
  ChangerMap cm;
  std::vector<int> v;
  v.push_back(4);
  cm.run(e,v,t);
  
  Combat & c = e->getRefCombat();
  e->setEnCombat(true);
	// Il faut penser à initialiser la clock dans createListe
  c.createListe(e->getPerso());
  c.tourSuivant(t);
}
