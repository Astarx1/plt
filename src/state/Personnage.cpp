#include "state.hpp"
#include "Personnage.h"

Personnage::Personnage (int niveau, TypePersonnage type) {
}

Personnage::~Personnage () {
}

TypePersonnage Personnage::getTypePersonnage () {
	return TypePersonnage ();
}

int Personnage::getForce () {
	return 0;
}

int Personnage::getNiveau () {
	return 0;
}

int Personnage::getPA () {
	return 0;
}

int Personnage::getPM () {
	return 0;
}

int Personnage::getVie () {
	return 0;
}

Attaque Personnage::getAttaqueDistance () {
	return Attaque ();
}

Attaque Personnage::getAttaqueCAC () {
	return Attaque ();
}

EtatPerso Personnage::getEtatPerso () {
	return EtatPerso ();
}

void Personnage::setTypePersonnage (TypePersonnage type) {
}

void Personnage::setForce (int i) {
}

void Personnage::setNiveau (int i) {
}

void Personnage::setPA (int i) {
}

void Personnage::setPM (int i) {
}

void Personnage::setVie (int i) {
}

void Personnage::setAttaqueDistance (Attaque attaqueDist) {
}

void Personnage::setAttaqueCAC (Attaque AttaqueCorps) {
}

void Personnage::setEtatPerso (EtatPerso etatPerso) {
}
