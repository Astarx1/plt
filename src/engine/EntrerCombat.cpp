
/* 
Besoin attribut/constructeur : 
Params :
0 -> id du personnage
1 -> nouveau xObj
2 -> nouveau yObj
*/

#include "../engine.h"
#include "../state.h"

#include <iostream>
#include <vector>

#define TRACE_ENTRERCOMBAT 1

using namespace engine;
using namespace state;

void EntrerCombat::run(Etat* e, std::vector<int> params,sf::Time t) {
  #if TRACE_ENTRERCOMBAT==1
  std::cout << "EntrerCombat::run : On commence par changer de map ..." << std::endl;
  #endif
  ChangerMap cm;
  std::vector<int> v;
  v.push_back(4);
  cm.run(e,v,t);
  
  #if TRACE_ENTRERCOMBAT==1
  std::cout << "EntrerCombat::run : On rentre en combat ..." << std::endl;
  #endif
  Combat & c = e->getRefCombat();
  e->setEnCombat(true);

  #if TRACE_ENTRERCOMBAT==1
  std::cout << "EntrerCombat::run : On initilise les conditions de combat ..." << std::endl;
  #endif
	// Il faut penser à initialiser la clock dans createListe
  c.createListe(e->getPerso());
  c.tourSuivant(t);

  #if TRACE_ENTRERCOMBAT==1
  std::cout << "EntrerCombat::run : On rentre en combat ..." << std::endl;
  #endif
}
