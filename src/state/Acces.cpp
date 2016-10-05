#include "state.hpp"
#include "Acces.h"

Acces::Acces (int i, int j) {
}

bool Acces::isAcces () {
	return false;
}

TypeID Acces::getTypeID () {
	return TypeID ();
}

void Acces::accepte (IVisiteur & v) {
}
