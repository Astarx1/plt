#include "../state.h"
#include "../render.h"

#include <iostream>

#define DHAUTEUR 24
#define DLARGEUR 24

#define TRACE_ETAT 1
#define TRACE_GETSTATUTGRILLE 0
#define TRACE_GETIDPERSO 1

using namespace state;
using namespace render;

Etat::Etat () : grille(1), personnages() {
	mapActuel = 1;
	loadGrille (1);
	enCombat = false;
}

Etat::~Etat () {
	;
}

TypeID Etat::getStatutGrille (int i, int j) {
	bool b = true;
	for (int k = 0; k < personnages.size(); ++k) {
		sf::Vector2f pos = getGrilleCoord((personnages.getElement(k))->getX(), (personnages.getElement(k))->getY());
		
		#if TRACE_ETAT == 1 && TRACE_GETSTATUTGRILLE == 1
			std::cout << "Etat::getStatutGrille : test du personnage X(" << pos.x << ") Y(" << pos.y << ")" << std::endl;
		#endif

		if (pos.x == i && pos.y == j) {
			#if TRACE_ETAT == 1  && TRACE_GETSTATUTGRILLE == 1
				std::cout << "Etat::getStatutGrille : Match des coordonnees" << std::endl;
				if((personnages.getElement(k))->getTypeID() == TypeID(PERSO))
					std::cout << "Etat::getStatutGrille : C'est un heros" << std::endl;
				else if((personnages.getElement(k))->getTypeID() == TypeID(MONSTRE))
					std::cout << "Etat::getStatutGrille : C'est un monstre" << std::endl;
				else 
					std::cout << "Etat::getStatutGrille : C'est autre chose..." << std::endl;
			#endif
			b = false;
			return (personnages.getElement(k))->getTypeID();
		}
	}

	if (b) {
		if (grille.isAcces(i, j)) {

			#if TRACE_ETAT == 1 && TRACE_GETSTATUTGRILLE == 1
				std::cout << "Etat::getStatutGrille : C'est un acces" << std::endl;
			#endif

			return ACCES;
		}
		else {

			#if TRACE_ETAT == 1 && TRACE_GETSTATUTGRILLE == 1
				std::cout << "Etat::getStatutGrille : C'est du vide " << std::endl;
			#endif

			return VIDE;
		}
	}
}

Personnage & Etat::getRefPersonnage (int n) {
	// TODO: insert return statement here
	
	Element & o = *(personnages.getElement(n));
	
	o.accepte (visiteur);
	TypeID a = o.getTypeID();
	
	if (a == TypeID(PERSO)) 
		return *(visiteur.getpHeros ());
	else  
		return *(visiteur.getpMonstre ());
}

int Etat::getIdPersonnage (int i, int j) {
	if (getStatutGrille(i,j) == TypeID(PERSO) || getStatutGrille(i,j) == TypeID(MONSTRE)) {
		int l;
		for (l = 0; l < personnages.size(); ++l) {
			sf::Vector2f pos = getGrilleCoord((personnages.getElement(l))->getX(), (personnages.getElement(l))->getY());
			#if TRACE_GETIDPERSO == 1 && TRACE_ETAT == 1
				std::cout << "Etat::getIdPersonnage : On verifie " << pos.x << " (" << i << ") - " << pos.y << " (" << j << ")" << std::endl;
			#endif
			if (i == pos.x && j == pos.y) {
				break;
			} 
		}
		return l;
	}
	else {
		return -1;
	}
}

void Etat::loadGrille (int n) {
	switch (n) {
		case 1:
			grille.charger("res/Textures/carte/map1.txt");
			break;
		case 2:
			grille.charger("res/Textures/carte/map2.txt");
			break;
		case 4:
			grille.charger("res/Textures/carte/map4.txt");
			break;
	}
}

GrilleElements& Etat::getGrille () {
	return grille;
}

bool Etat::getEnCombat () {
	return enCombat;
}

void Etat::setEnCombat (bool b) {
	enCombat = b; 
}

void Etat::rajouterPerso (char e) { 
	personnages.ajoutElement (e);
}

void Etat::enleverPerso (int i) {
	// Impossible tant que l'on n'a pas impl�ment� la suppression d'�l�ment
	// Dans ListeElements
}

Combat & Etat::getRefCombat () {
	// TODO: insert return statement here
	return combat;
}

int Etat::getMapActuel () {
	return mapActuel;
}

void Etat::setMapActuel (int i) {
	mapActuel = i;
	loadGrille(i);
}

ListeElements& Etat::getPerso (){
	return personnages;
}

int Etat::getPersoSize() {
	return personnages.size();
}

Statique & Etat::getTile (int n) {
	// TODO: insert return statement here
	
	Element & o = *(grille.getElement(n));
	
	o.accepte (visiteur);
	TypeID a = o.getTypeID();
	
	if (a == TypeID(VIDE)) 
		return *(visiteur.getpVide ());
	else  
		return *(visiteur.getpAcces ());
}

Heros& Etat::getRefHeros(int id){
    
    Element & o = *(personnages.getElement(id));
	
    o.accepte (visiteur);
    TypeID a = o.getTypeID();
	
    if (a == TypeID(PERSO)) 
        return *(visiteur.getpHeros ());
	 
}

sf::Vector2f Etat::getGrilleCoord(int x, int y){
	int sx = grille.getTile(0)->getX();
	int sy = grille.getTile(0)->getY();
  	
  	int rx = -1;
  	int ry = -1;
  	if (x >= sx && x <= sx+DLARGEUR*2*grille.getLargeur()) { 	
  		for (rx = 0; sx+rx*DLARGEUR*2 < x ;rx++) {
		}
    }
  	
  	if (y >= sy && y <= sy+DHAUTEUR*2*grille.getLongueur()) {
		for (ry = 0; sy+ry*DLARGEUR*2 < y ;ry++) {
		}
    }
  
  	return sf::Vector2f(rx, ry);
}

sf::Vector2f Etat::getCoordTile(int x, int y){
  	return sf::Vector2f(x*DLARGEUR*2, y*DHAUTEUR*2);
}

sf::Vector2f Etat::getGrilleTile (int id) {
	return sf::Vector2f(0,0);
}

int Etat::getIdTile (int i, int j) {
	return 0;
}

void Etat::clearPersos() {
	personnages.clear();
}

void Etat::clearGrille () {
	grille.clear();
}

void Etat::addPerso (Personnage * p) {
	personnages.ajoutElement(p);
}

