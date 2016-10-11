#include "Monstre.h"
#include "Visiteur.h"
using namespace state;

Monstre::Monstre (int i, int j, int nv) : Personnage (i, HEROS) {
    this->x=i;
    this->y=j;
    this->niveau=nv;
}

bool Monstre::isJoueur () {
	return false;
}

TypeID Monstre::getTypeID () {
	return TypeID ();
}

void Monstre::accepte (IVisiteur & v) {
    v.visiter(this);
}
