#include "Monstre.h"
#include "Visiteur.h"
using namespace state;

Monstre::Monstre (int i, int j, int nv) : Personnage (i, TypePersonnage(MONSTRE1)) {
    this->x=i;
    this->y=j;
    this->niveau=nv;
    this->typeID=MONSTRE;
}

Monstre::Monstre(int i, int j, int nv, TypePersonnage type):Personnage(nv,type){
   this->x=i;
   this->y=j; 
}

bool Monstre::isJoueur () {
	return false;
}

TypeID Monstre::getTypeID () {
	return TypeID (MONSTRE);
}

void Monstre::accepte (IVisiteur & v) {
    v.visiter(this);
}
