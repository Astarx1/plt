#include "Vide.h"
#include "Visiteur.h"

using namespace state;

Vide::Vide (int i, int j) {
    this->x=i;
    this->y=j;
    this->typeID=VIDE;
}

bool Vide::isAcces () {
	return false;
}

TypeID Vide::getTypeID () {
	return TypeID(VIDE);
}

void Vide::accepte (IVisiteur & v) {
    v.visiter(this);
}
