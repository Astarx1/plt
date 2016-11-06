#include "../state.h"
#include "../render.h"

#include <iostream>

#define DHAUTEUR 16
#define DLARGEUR 16

using namespace state;
using namespace render;

Etat::Etat () : grille(1), personnages() {
	std::cout << "Etat.cpp - constructeur : creation de la grille" << std::endl;
	mapActuel = 1;
	loadGrille (1);
	enCombat = false;
}

Etat::~Etat () {
	;
}

TypeID Etat::getStatutGrille (int i, int j) {
	if (grille.isAcces(i, j))
		return ACCES;
	else
		return VIDE;
}

Personnage & Etat::getRefPersonnage (int n) {
	// TODO: insert return statement here
	
	Element & o = *(personnages.getElement(n));
	
	o.accepte (visiteur);
	TypeID a = o.getTypeID();
	
	if (a == TypeID(HEROS)) 
		return *(visiteur.getpHeros ());
	else  
		return *(visiteur.getpMonstre ());
}

Personnage & Etat::getRefPersonnage (int i, int j) {
	Element & o = *(personnages.getElement (i));
	o.accepte (visiteur);
	return *(visiteur.getpHeros ());
}

void Etat::loadGrille (int n) {
	switch (n) {
		case 1:
			grille.charger("res/Textures/carte/map1.txt");
			break;
	}
}

GrilleElements Etat::getGrille () {
	return GrilleElements (1);
}

bool Etat::getEnCombat () {
	return enCombat;
}

void Etat::setEnCombat (bool b) {
	enCombat = b; 
}

void Etat::rajouterPerso (char e) { 
	personnages.ajoutElement (e);
	std::cout << "Etat.cpp - Rajout de personnage : Personnage rajoute - Nb elements : " << personnages.size() << std::endl;
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

ListeElements Etat::getPerso (){
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
	
    if (a == TypeID(HEROS)) 
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
  	return sf::Vector2f(x*DLARGEUR*2, (y+1)*DHAUTEUR*2);
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

