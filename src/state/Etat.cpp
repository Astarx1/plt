#include "state.hpp"
#include "Etat.h"

Etat::Etat () : grille(1), personnages() {
	Heros t (1, 1, 100);
	personnages.ajoutElement (&t);
}

Etat::~Etat () {
}

TypeID Etat::getStatutGrille (int i, int j) {
	return TypeID ();
}

Personnage & Etat::getRefPersonnage (int n) {
	// TODO: insert return statement here
	Element & o = *(personnages.getElement(n));
	o.accepte (visiteur);
	return *(visiteur.getpHeros ());
}

Personnage & Etat::getRefPersonnage (int i, int j) {
	Element & o = *(personnages.getElement (i));
	o.accepte (visiteur);
	return *(visiteur.getpHeros ());
}

void Etat::loadGrille (int n) {
}

GrilleElements Etat::getGrille () {
	return GrilleElements (1);
}

bool Etat::getEnCombat () {
	return false;
}

void Etat::setEnCombat (bool b) {
}

void Etat::rajouterPerso () {
}

void Etat::enleverPerso (int i) {
}

Combat & Etat::getRefCombat () {
	// TODO: insert return statement here
	return Combat ();
}

int Etat::getMapActuel () {
	return 0;
}

void Etat::setMapActuel (int i) {
}
