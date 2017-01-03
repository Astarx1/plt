#include "../engine.h"
#include <ctime>
#include <iostream>
#include "../state.h"

#define TRACE_REGLE 0
#define TRACE_REGLE_CHANGER_MAP 0

using namespace state;
using namespace sf;


namespace engine {

/* Cette fonction permet de vérifier si le joueur peut se déplacer à la nouvelle
 * position (newX,newY)
 * 
 * À compléter!!!
 */   
bool Regles::peutDeplacer(state::Etat* e, int id, int newX, int newY){
	//(e->accesPerso())->lock();
	if (id < e->getPersoSize()) {
		Personnage& perso = e->getRefPersonnage(id);
		if(e->getEnCombat()){
			// Si le personnage est en combat
			/*TypeID typeTmp = e->getStatutGrille(newX,newY);
			if(perso.getPM() == 0){
				return false;
			}
			else if (typeTmp != PERSO && typeTmp != MONSTRE){
				return false;
				// Penser au cas en réseau où il peut y avoir d'autre héros
			}*/
			Combat & c = e->getRefCombat();
			if (id != c.getTour())
				return false; 
		}
		else{
			// Si le personnage n'est pas en combat
			if((newY > 1000 || newX > 1000) || (newX < 1 || newY < 1)){
				// Seuil à ajuster!
				return false;
			}
		}
	}
	else {
		return false;
	}
	//(e->accesPerso())->unlock();
	return true;
}

/* Cette fonction permet de vérifier si un personnage de type Heros peut entrer
 * en combat. 
 */
bool Regles::peutEntrerCombat (state::Etat* e, int id){
	Personnage& perso = e->getRefPersonnage(id);
	if(perso.isJoueur()){
		if(e->getEnCombat() == false){
			return true;
		}
	else {
		return false; 
	}
	}
	else{
		return false;
	}
}

/*Cette fonction permet de vérifier si le joueur se trouve sur une case ACCES
 *afin de pourvoir changer de carte
 */
bool Regles::peutChangerMap (state::Etat* e, int id){    
	Personnage& perso = e->getRefPersonnage(id);
	sf::Vector2f vect=e->getGrilleCoord(perso.getXobj(),perso.getYobj());
	
	#if TRACE_REGLE==1 && TRACE_REGLE_CHANGER_MAP==1
		std::cout<<"X:"<<vect.x <<" Y:"<<vect.y<<std::endl;
	#endif
	
	if(((e->getGrille()).isAcces(vect.x,vect.y))){

		#if TRACE_REGLE==1 && TRACE_REGLE_CHANGER_MAP==1
			std::cout<<"Regles::peutChangerMap return true"<<std::endl;
		#endif
		return true;
	}
	
	#if TRACE_REGLE==1 && TRACE_REGLE_CHANGER_MAP==1
		std::cout<<"Regles::peutChangerMap return false"<<std::endl;
	#endif
	return false;
}

/* Cette fonction permet de vérifier s'il est possible de quitter le mode combat.
 */
bool Regles::peutQuitterCombat(state::Etat* e){
	bool retH = false;
	bool retM = false;
	ListeElements persos = e->getPerso();
	
	for(size_t i=0; persos.size(); i++){
		if(e->getRefPersonnage(i).getTypeID() == TypeID(PERSO) && e->getRefPersonnage(i).getVie() >0){
			retH = true;
		}
		if(e->getRefPersonnage(i).getTypeID() == TypeID(MONSTRE) && e->getRefPersonnage(i).getVie() >0){
			retM = true;
		}
	}
	return !(retH && retM);
		
}

bool Regles::peutAttaquer(state::Etat* e, int id){
	Personnage& perso = e->getRefPersonnage(id);
	bool ret = false;
	
	if(e->getEnCombat()){
		if(perso.getPA() > 0){
			ret = true;
		}
	}
	else{
		ret = true;
	}
	
	return ret;
}

bool Regles::doitPasserTour(state::Etat* e, int id, sf::Time t){
	Combat& combat = e->getRefCombat();
	Time timeDeb = combat.getTimerDebutTour();
	if((t.asSeconds()- timeDeb.asSeconds()) >= 60){
		return true;
	}
	return false;
}

bool Regles::peutAccederMenu(state::Etat* e){
	if(e->getEnCombat()){
		return false;
	}
	else{
		return false;
	}
}

bool Regles::peutAccederInfoPerso(state::Etat* e){
	if(e->getEnCombat()){
		return false;
	}
	else{
		return false;
	}
}

bool Regles::peutAugmenterNiv(state::Etat* e, int id){
	int nv = e->getRefPersonnage(id).getNiveau();
	int exp = e->getRefHeros(id).getExp();
	
	if(exp >= nv*100){
		return true;
	}
	
	return false;
  
}

int Regles::augmenterPM(state::Etat* e, int id){
	int nv = e->getRefPersonnage(id).getNiveau();
	
	switch(nv){
		case 1:
			return 3;
		break;
		case 2:
			return 4;
		break;
		case 3:
			return 5;
		break;
		case 4:
			return 6;
		break;
		case 5:
			return 7;
		break;
		case 6:
			return 8;
		break;
		case 7:
			return 9;
		break;
		case 8:
			return 10;
		break;
		case 9:
			return 11;
		break;
		case 10:
			return 12;
		break;
	}
	return 0;
}

int Regles::augmenterPA(state::Etat* e, int id){
	int nv = e->getRefPersonnage(id).getNiveau();
	
	switch(nv){
		case 1:
			return 6;
		break;
		case 2:
			return 7;
		break;
		case 3:
			return 8;
		break;
		case 4:
			return 9;       
		break;
		case 5:
			return 10;
		break;
		case 6:
			return 11;
		break;
		case 7:
			return 12;
		break;
		case 8:
			return 13;        
		break;
		case 9:
			return 14;
		break;
		case 10:
			return 15;
		break;
	}
	return 0;
}

int Regles::augmenterPV(state::Etat* e, int id){
	int nv = e->getRefPersonnage(id).getNiveau();
	
	switch(nv){
		case 1:
			return 150;
		break;
		case 2:
			return 200;
		break;
		case 3:
			return 250;
		break;
		case 4:
			return 300;
		break;
		case 5:
			return 350;       
		break;
		case 6:
			return 400;
		break;
		case 7:
			return 450;
		break;
		case 8:
			return 500;
		break;
		case 9:
			return 550;
		break;
		case 10:
			return 600;
		break;
	}
	return 0;
}

int Regles::augmenterForce(state::Etat* e, int id){
	int nv = e->getRefPersonnage(id).getNiveau();
	
	switch(nv){
		case 1:
			return 3;
		break;
		case 2:
			return 4;
		break;
		case 3:
			return 5;
		break;
		case 4:
			return 6;
		break;
		case 5:
			return 7;
		break;
		case 6:
			return 8;
		break;
		case 7:
			return 9;
		break;
		case 8:
			return 10;
		break;
		case 9:
			return 11;
		break;
		case 10:
			return 12;
		break;
	}
	return 0;
}

/* Cette fonction permet de définir les monstres associés à la carte
 * 
 * À prévoir la génération des positions aléatoires pour l'instanciation des monstres.
 */
std::vector<state::Personnage*> Regles::defMonstreCarte(state::Etat* e){

	srand(time(NULL));
	std::vector<state::Personnage*> list;
	GrilleElements g = e->getGrille();
	int map_actuel = e->getMapActuel();
	int nb_monstre = 4;
		int alea_monstre = 1;

	switch(map_actuel){
		case 1: 
			for(int i=2; i<g.getLargeur()-2; i++){
		for (int i=2; i<g.getLongueur()-2; i++){
			int y=rand()%20;
				if(y == 0 && nb_monstre > 0){
				 nb_monstre--;
					Monstre p(1,1,1,MONSTRE1);
					list.push_back(&p);
				}
				else if (y == 1 && nb_monstre > 0){
					Monstre p(1,1,1,MONSTRE2);
					list.push_back(&p);
				}
		}
			}
			return list;
		break;
			
		case 2:
			for(int i=0; i<alea_monstre; i++){
				int alea_nv = rand()%6 + 4;
				if(rand()%2 == 0){
					Monstre p(1,1,alea_nv,MONSTRE3);
					list.push_back(&p);
				}
				else{
					Monstre p(1,1,alea_nv,MONSTRE4);
					list.push_back(&p);
				}
			}
			return list;
		break;
			
		case 3:
			Monstre p(1,1,10,BOSS);
			list.push_back(&p);
			return list;
		break;
	}
	
}

int Regles::defCarteSuiv (state::Etat* e, int id){
	int mapSuiv = e->getMapActuel();
	//(e->accesPerso())->lock();
	if (id < e->getPersoSize()) {
		Personnage& perso = e->getRefPersonnage(id);
		int map_actuel = e->getMapActuel();
		bool combat = e->getEnCombat();
		mapSuiv = 0;
		sf::Vector2f vect=e->getGrilleCoord(perso.getXobj(),perso.getYobj());
		int x = vect.x;
		int y = vect.y;
		#if TRACE_REGLE_CHANGER_MAP==1 && TRACE_REGLE==1
			std::cout<<" Regles::defCarteSuiv : On entre dans la fonction : "<< map_actuel << " x = " << x << " y = " << y <<std::endl;
		#endif
		
		switch(map_actuel){
			case 1: 
				if(combat)
					mapSuiv = 4;
				else if(e->getGrille().isAcces(x,y))
					mapSuiv = 2;
				//return mapSuiv;
			break;
			case 2:
				if(combat)
					mapSuiv = 4;
				else if(e->getGrille().isAcces(x,y)){
					if(x < 10)
						mapSuiv = 1;
					else
					   mapSuiv = 3;
				}                
				//return mapSuiv;
			break;
			case 3:
				if(combat)
					mapSuiv = 4;
				else if(e->getGrille().isAcces(x,y))
					mapSuiv = 2;
				//return mapSuiv;
			break;
			
				
		}
		#if TRACE_REGLE_CHANGER_MAP==1 && TRACE_REGLE==1
			std::cout<<" Regles::defCarteSuiv : On sort dans la fonction : "<< mapSuiv <<std::endl;
		#endif
	}
	//(e->accesPerso())->unlock();
	return mapSuiv;
}

};
