#include "../engine.h"
#include "../state.h"
#include <vector>
#include <iostream>
#include <assert.h>

#define TRACE_CM 0
#define TRACE_CM_RUN 1
#define TRACE_CM_DEFMC 1

using namespace state;
using namespace engine;
 
/* Params : 
0 -> nummero de la nouvelle map 
Toudoux : Clear les perso d'Etat, clear la grille
Regle renvoyant les monstres sous formes de std::vector<Personnages&>
*/

std::vector<state::Personnage*> defMonstreCarte(state::Etat* e) {
	srand(time(NULL));
	std::vector<state::Personnage*> list;
	//GrilleElements g = e->getGrille();
	int map_actuel = e->getMapActuel();
	int nb_monstre_max = 4;
	int alea_monstre = 1;

	if (map_actuel == 1) { 
		for(int i=12; i<14; i++){
			for (int j=5; j<10; j++){
				int y=rand()%5;
				#if TRACE_CM==1 && TRACE_CM_DEFMC == 1
					std::cout << "ChangerMap::defMonstreCarte : Choix aleatoire : " << y << std::endl;
				#endif
				sf::Vector2f pos = e->getCoordTile(i, j);
				
				if(y == 0 && nb_monstre_max > 0){
					nb_monstre_max--;
					e->rajouterPerso ('m');
					Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);
					p.setTypePersonnage(TypePersonnage(MONSTRE3));
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
					p.setTypePersonnage(TypePersonnage(MONSTRE4));
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
	}

	else if (map_actuel == 2) { 
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
	}
		
	else if (map_actuel == 3) { 
		sf::Vector2f pos = e->getCoordTile(15, 10);
		e->rajouterPerso ('m');
		Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);
		p.setTypePersonnage(TypePersonnage(BOSS));
		p.setEnDeplacement(false);
		p.setDirection(OUEST);
		p.setX(pos.x);
		p.setXobj(pos.x);
		p.setY(pos.y);
		p.setYobj(pos.y);
				list.push_back(&p);
		return list;
	}

	else if (map_actuel == 4) { 
		for(int i=12; i<14; i++){
			for (int j=5; j<10; j++){
				int y=rand()%5;
				#if TRACE_CM==1 && TRACE_CM_DEFMC == 1
					std::cout << "ChangerMap::defMonstreCarte : Choix aleatoire : " << y << std::endl;
				#endif
				sf::Vector2f pos = e->getCoordTile(i, j);
				
				if(y == 0 && nb_monstre_max > 0){
					nb_monstre_max--;
					e->rajouterPerso ('m');
					Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);
					p.setTypePersonnage(TypePersonnage(MONSTRE3));
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
					p.setTypePersonnage(TypePersonnage(MONSTRE4));
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
	}
}

void ChangerMap::run (Etat* e, std::vector<int> params,sf::Time t) {
	assert(params[0] == 1 || params[0] == 2 || params[0] == 3 || params[0] == 4);

  	(e->accesPerso())->lock();
	// On commence par sauvegarder les personnages joueurs
	std::vector<Personnage*> persos;
	for (int i = 0; i < e->getPersoSize(); ++i) {
		Personnage& ptmp = e->getRefPersonnage(i);
		sf::Vector2f pos = e->getGrilleCoord(ptmp.getX(),ptmp.getY()); 
		
		if (ptmp.getTypePersonnage() == TypePersonnage(HEROS) || ptmp.getTypePersonnage() == TypePersonnage(HEROINE)) {
			persos.push_back(new Heros(1, 1, 1));

			sf::Vector2f pos = e->getCoordTile(10, 10+i);
			(persos[persos.size() - 1])->setX (pos.x);
			(persos[persos.size() - 1])->setY (pos.y);
			(persos[persos.size() - 1])->setXobj (pos.x);
			(persos[persos.size() - 1])->setYobj (pos.y);

			(persos[persos.size() - 1])->setTypePersonnage (ptmp.getTypePersonnage());

			(persos[persos.size() - 1])->setVie (ptmp.getVie());
			(persos[persos.size() - 1])->setForce (ptmp.getForce());
			(persos[persos.size() - 1])->setNiveau (ptmp.getNiveau());
			(persos[persos.size() - 1])->setAttaqueDistance (ptmp.getAttaqueDistance());
			(persos[persos.size() - 1])->setAttaqueCAC (ptmp.getAttaqueCAC());
			(persos[persos.size() - 1])->setEtatPerso (ptmp.getEtatPerso());

			#if TRACE_CM==1 && TRACE_CM_RUN==1
				std::cout<< "ChangerMap::run : Pointeur perso (" << ptmp.getVie() << " / " << (persos[persos.size() - 1])->getVie() << ") ..." << std::endl;
			#endif
		}/*
		else if(pos.x == params[1] && pos.y == params[2]){
			#if TRACE_CM_RUN==1
				std::cout<<" Type = " << ptmp.getTypePersonnage()<< " X = " << params[1]<< " Y = "<<params[2]<< std::endl;
			#endif
			
			persos.push_back(new Monstre(1,1,1));
				
			 sf::Vector2f pos = e->getCoordTile(16, 5+i);
			(persos[persos.size() - 1])->setX (pos.x);
			(persos[persos.size() - 1])->setY (pos.y);
			(persos[persos.size() - 1])->setXobj (pos.x);
			(persos[persos.size() - 1])->setYobj (pos.y);
			(persos[persos.size() - 1])->setTypePersonnage (ptmp.getTypePersonnage());
			(persos[persos.size() - 1])->setVie (ptmp.getVie());
			(persos[persos.size() - 1])->setForce (ptmp.getForce());
			(persos[persos.size() - 1])->setNiveau (ptmp.getNiveau());
			(persos[persos.size() - 1])->setAttaqueDistance (ptmp.getAttaqueDistance());
			(persos[persos.size() - 1])->setAttaqueCAC (ptmp.getAttaqueCAC());
			(persos[persos.size() - 1])->setEtatPerso (ptmp.getEtatPerso());			
		}*/
	}
  
	e->clearPersos();
	#if TRACE_CM==1 && TRACE_CM_RUN==1
		std::cout<<"ChangerMap::run : changement de map (" << params[0] << ") ..."<<std::endl;
	#endif
	GrilleElements& ge = e->getGrille();
	switch(params[0]) {
		case 1:
			ge.setLongueur(14);
			ge.setLargeur(20);
			break;
		case 2:
			ge.setLongueur(14);
			ge.setLargeur(20);
			break;
		case 4:
			ge.setLongueur(14);
			ge.setLargeur(20);
	}
	e->setMapActuel(params[0]);

	for (auto d : persos) {
		e->rajouterPerso ('h');
		Personnage &p = e->getRefPersonnage(e->getPersoSize()-1);

		p.setTypePersonnage(d->getTypePersonnage());
		p.setEnDeplacement(false);
		if(d->getTypePersonnage()==HEROS || d->getTypePersonnage()==HEROINE)
					p.setDirection(OUEST);
		else
					p.setDirection(EST);
		p.setX(d->getX());
		p.setXobj(d->getXobj());
		p.setY(d->getY());
		p.setYobj(d->getYobj());

		p.setVie(d->getVie());
		p.setForce(d->getForce());
		p.setNiveau(d->getNiveau());
		p.setAttaqueDistance(d->getAttaqueDistance());
		p.setAttaqueCAC(d->getAttaqueCAC());
		p.setEtatPerso(d->getEtatPerso());

		#if TRACE_CM==1 && TRACE_CM_RUN==1
			std::cout<<"ChangerMap::run : Perso (" << p.getVie() << " / " << d->getVie() << ") ..." << std::endl;
		#endif
		
		delete d;
	}

	defMonstreCarte(e);
	(e->accesPerso())->unlock();
	e->notifyObserver('g',t);
}


