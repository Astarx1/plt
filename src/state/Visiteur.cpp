#include "Visiteur.h"

using namespace state;

void Visiteur::visiter (Heros * pHeros) {
	lastype = 1;
	this->pHeros = pHeros;
}

void Visiteur::visiter (Vide * pVide) {
	lastype = 2;
	this->pVide = pVide;
}

void Visiteur::visiter (Acces * pAcces) {
	lastype = 3;
	this->pAcces = pAcces;
}

void Visiteur::visiter (Monstre * pMonstre) {
	lastype = 4;
	this->pMonstre = pMonstre;
}

Heros * Visiteur::getpHeros () {
	return pHeros;
}

  Monstre* Visiteur::getpMonstre () {
	return pMonstre;
  }
  
  Acces* Visiteur::getpAcces () {
	return pAcces;
  }
  
  Vide* Visiteur::getpVide () {
	return pVide;
  }
