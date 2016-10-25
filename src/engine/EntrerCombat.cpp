
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

void EntrerCombat::run(Etat* e, std::vector<int> params) {
  	// On commence par sauvegarder les personnages joueurs
	std::vector<Personnage*> p;
  	for (int i = (e->getPerso()).size() - 1; i >= 0; --i) {
    	Personnage& ptmp = e->getRefPersonnage(i);
      	if (ptmp.getTypePersonnage() == TypePersonnage(HEROS) || ptmp.getTypePersonnage() == TypePersonnage(HEROINE)) {
        	p.push_back(&ptmp);  
        }
  	}
    
  	std::vector <Personnage*> pmonstre;
  	// Insérer ici l'appel aux règles pour obtenir les monstres
	for (auto d : pmonstre) 
		p.push_back (d);
  
    for (int i = 0; i < p.size(); ++i) {
		// Inserer ici la commande pour ajouter un perso à Etat avec un passage par référence
    }
  
  	Combat & c = e->getRefCombat();
  	e->setEnCombat(true);
  	// Il faut penser à initialiser la clock dans createListe
  	c.createListe(e->getPerso());
}
