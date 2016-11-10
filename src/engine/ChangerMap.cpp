#include "../engine.h"
#include "../state.h"
#include <vector>
#include <iostream>

using namespace state;
using namespace engine;
 
/* Params : 
0 -> nummero de la nouvelle map 
Toudoux : Clear les perso d'Etat, clear la grille
Regle renvoyant les monstres sous formes de std::vector<Personnages&>
*/

std::vector<state::Personnage*> defMonstreCarte(state::Etat* e){
    srand(time(NULL));
    std::vector<state::Personnage*> list;
	GrilleElements g = e->getGrille();
    int map_actuel = e->getMapActuel();
    int nb_monstre_max = 4;
        int alea_monstre = 1;

    switch(map_actuel){
        case 1: 
            for(int i=12; i<14; i++){
		for (int j=5; j<10; j++){
			int y=rand()%20;
			sf::Vector2f pos = e->getCoordTile(i, j);
		        if(y == 0 && nb_monstre_max > 0){
				nb_monstre_max--;
				e->rajouterPerso ('m');
				Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);
				p.setTypePersonnage(TypePersonnage(MONSTRE1));
				p.setEnDeplacement(false);
				p.setDirection(OUEST);
				p.setX(pos.x);
				p.setXobj(pos.x);
				p.setY(pos.y);
				p.setYobj(pos.y);
		            	list.push_back(&p);
		        }
		        else if (y == 1 && nb_monstre_max > 0){
				nb_monstre_max--;
				e->rajouterPerso ('m');
				Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);
				p.setTypePersonnage(TypePersonnage(MONSTRE2));
				p.setEnDeplacement(false);
				p.setDirection(OUEST);
				p.setX(pos.x);
				p.setXobj(pos.x);
				p.setY(pos.y);
				p.setYobj(pos.y);
		            	list.push_back(&p);
		        }
		}
            }
            return list;
            
        case 2:
			break;
            
        case 3:
		break;
    }
    
}

void ChangerMap::run (Etat* e, std::vector<int> params,sf::Time t) {
  	// On commence par sauvegarder les personnages joueurs
	std::vector<Personnage*> persos;
  	for (int i = 0; i < e->getPersoSize(); ++i) {
	    	Personnage& ptmp = e->getRefPersonnage(i);
	      	if (ptmp.getTypePersonnage() == TypePersonnage(HEROS) || ptmp.getTypePersonnage() == TypePersonnage(HEROINE)) {
			persos.push_back(new Heros(1, 1, 1));
			sf::Vector2f pos = e->getCoordTile(10, 10+i);
			(persos[persos.size() - 1])->setX(pos.x);
			(persos[persos.size() - 1])->setY(pos.y);
			(persos[persos.size() - 1])->setXobj(pos.x);
			(persos[persos.size() - 1])->setYobj(pos.y);
			(persos[persos.size() - 1])->setTypePersonnage(ptmp.getTypePersonnage());
		}
  	}
  
  	e->clearPersos();

  	e->setMapActuel(params[0]);
 
	for (auto d : persos) {
		e->rajouterPerso ('h');
		Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);

		p.setTypePersonnage(d->getTypePersonnage());
		p.setEnDeplacement(false);
		p.setDirection(OUEST);
		p.setX(d->getX());
		p.setXobj(d->getXobj());
		p.setY(d->getY());
		p.setYobj(d->getYobj());
		delete d;
	}

	defMonstreCarte(e);	
}
