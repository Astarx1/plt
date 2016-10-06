#include "state.hpp"
#include "Visiteur.h"

void Visiteur::visiter (Heros * pHeros) {
	lastype = 
	this->pHeros = pHeros;
}

void Visiteur::visiter (Vide * pVide) {
	this->pVide = pVide;
}

void Visiteur::visiter (Acces * pAcces) {
}

void Visiteur::visiter (Monstre * pMonstre) {
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