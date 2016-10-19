#include "Etat.h"
#include "Heros.h"

using namespace state;

Etat::Etat () : grille(1), personnages() {
	;
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
	if (a == PERSO) 
		return *(visiteur.getpHeros ());
	else if (a == MONSTRE)
		return *(visiteur.getpMonstre ());
}

Personnage & Etat::getRefPersonnage (int i, int j) {
	Element & o = *(personnages.getElement (i));
	o.accepte (visiteur);
	return *(visiteur.getpHeros ());
}

void Etat::loadGrille (int n) {
	grille.charger("test");
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
}

void Etat::enleverPerso (int i) {
	// Impossible tant que l'on n'a pas implémenté la suppression d'élément
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
}

ListeElements Etat::getPerso (){
	return personnages;
}

int Etat::getPersoSize() {
	return personnages.size();
}
