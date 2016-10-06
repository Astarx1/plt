#include "state.hpp"
#include "GrilleElements.h"

GrilleElements::GrilleElements (int nv) {
    switch (nv)
    {
    case 1:
    {
        this->largeur=600;
        this->longueur=900;
    }
    case 2:
    {
        this->largeur=600;
        this->longueur=900;
    }
    case 3:
    {
        this->largeur=600;
        this->longueur=600;
    }
    }
}

int GrilleElements::getLongueur () {
	return this->longueur;
}

int GrilleElements::getLargeur () {
	return this->largeur;
}

bool const GrilleElements::isAcces (int i, int j) {
    return nullptr;
}

void GrilleElements::setCase (Element * e, int i, int j) {
    e->setX(i);
    e->setY(j);
}

void GrilleElements::charger (const char * nom_fichier) {
}

void GrilleElements::setLongueur (int i) {
    this->longueur=i;
}

void GrilleElements::setLargeur (int i) {
    this->largeur=i;
}

void GrilleElements::ajoutCaseAcces (int i, int j) {
    Element * e;
    this->ajoutElement(e);
    e->setX(i);
    e->setY(j);
    // e.setTypeID(2) //en attente ajout de la méthode dans élement
    
}
