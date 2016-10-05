#include "state.hpp"
#include "Heros.h"

Heros::Heros (int i, int j, int exp) : Personnage (i, HEROS) {
}

bool Heros::isJoueur () {
	return false;
}

TypeID Heros::getTypeID () {
	return TypeID ();
}

int const Heros::getExp () {
	return 0;
}

void Heros::setExp (int const Exp) {
}

void Heros::accepte (IVisiteur & v) {
}
