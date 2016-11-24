#include "../ia.h"

#include <vector>

using namespace ia;
using namespace state;

Arbre::Arbre () {
	Racine = new Noeud (nullptr, 0, nullptr);
	profondeur = 0;
}

Arbre::~Arbre () {
	delete Racine;
}

void Arbre::creerArbre (state::ListeElements& lp, int npro) {
	Racine = new Noeud (nullptr, 0, nullptr);
	profondeur = npro;
	Racine->createFils(lp, profondeur);
}

int Arbre::MinMax (bool heros) {
	if (profondeur > 0) {
		return Racine->MinMax(heros);
	}
	else {
		return -1;
	}
}