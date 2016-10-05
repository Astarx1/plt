#include "state.hpp"
#include "Visiteur.h"

void Visiteur::visiter (Heros * pHeros) {
}

void Visiteur::visiter (Vide * pVide) {
}

void Visiteur::visiter (Acces * pAcces) {
}

void Visiteur::visiter (Monstre * pMonstre) {
}

Heros * Visiteur::getpHeros () {
	return pHeros;
}
