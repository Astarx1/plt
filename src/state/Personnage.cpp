#include "Personnage.h"

using namespace state;

Personnage::Personnage (int niveau, TypePersonnage type) {
    this->niveau = niveau;
    this->typePerso = type;
}

Personnage::~Personnage () {
}

TypePersonnage Personnage::getTypePersonnage () {
	return this->typePerso;
}

int Personnage::getForce () {
	return this->force;
}

int Personnage::getNiveau () {
	return this->niveau;
}

int Personnage::getPA () {
	return this->ptAction;
}

int Personnage::getPM () {
	return this->ptMouvement;
}

int Personnage::getVie () {
	return vie;
}

Attaque Personnage::getAttaqueDistance () {
	return this->attaqueDistance;
}

Attaque Personnage::getAttaqueCAC () {
	return this->attaqueCAC;
}

EtatPerso Personnage::getEtatPerso () {
	return this->etatPerso;
}

void Personnage::setTypePersonnage (TypePersonnage type) {
    this->typePerso = type;
}

void Personnage::setForce (int i) {
    this->force = i;
}

void Personnage::setNiveau (int i) {
    this->niveau = i;
}

void Personnage::setPA (int i) {
    this->ptAction = i;
}

void Personnage::setPM (int i) {
    this->ptMouvement = i;
}

void Personnage::setVie (int i) {
    vie = i;
}

void Personnage::setAttaqueDistance (Attaque attaqueDist) {
    this->attaqueDistance = attaqueDist;
}

void Personnage::setAttaqueCAC (Attaque AttaqueCorps) {
    this->attaqueCAC = AttaqueCorps;
}

void Personnage::setEtatPerso (EtatPerso etatPerso) {
    this->etatPerso = etatPerso;
}
