#include "state.hpp"
#include "Vide.h"

Vide::Vide (int i, int j) {
}

bool Vide::isAcces () {
	return false;
}

TypeID Vide::getTypeID () {
	return TypeID ();
}

void Vide::accepte (IVisiteur & v) {
}
