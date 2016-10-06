#include "state.hpp"
#include "Attaque.h"

Attaque::Attaque () {
}

Attaque::~Attaque () {
}

int Attaque::getCoutPA () {
	return this->coutPA;
}

void Attaque::setCoutPA (int i) {
    this->coutPA = i;
}
