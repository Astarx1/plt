#include "state.hpp"
#include "Acces.h"

Acces::Acces (int i, int j) {

    this->x=i;
    this->y=j;
    this->typeID=ACCES;
}

bool Acces::isAcces () {
	return true;
}

TypeID Acces::getTypeID () {
	return TypeID ();
}

void Acces::accepte (IVisiteur & v) {
    v.visiter(this);
}
