#include "Visiteur.h"

using namespace state;

void Visiteur::visiter (Heros * pHeros) {
	lastType = 1;
	this->pHeros = pHeros;
}

void Visiteur::visiter (Vide * pVide) {
	lastType = 2;
	this->pVide = pVide;
}

void Visiteur::visiter (Acces * pAcces) {
	lastType = 3;
	this->pAcces = pAcces;
}

void Visiteur::visiter (Monstre * pMonstre) {
	lastType = 4;
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
