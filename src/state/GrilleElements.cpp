#include "GrilleElements.h"
#include "Statique.h"
#include "../state.h"
#include "../render.h"

using namespace state;
using namespace render;

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
    return false;
}

void GrilleElements::setCase (Element * e, int i, int j) {
    e->setX(i);
    e->setY(j);
}

void GrilleElements::charger (char * nom_fichier) {
	elements.clear();
	Parseur p;
	std::vector<int> l = p.ParsingMap(nom_fichier);
	
	for (int i = 0; i < l.size(); ++i) {
		ajoutElement('v');
		Statique * a = getTile(elements.size()-1);
		a->setTile(l[i]);
	}
}

void GrilleElements::setLongueur (int i) {
    this->longueur=i;
}

void GrilleElements::setLargeur (int i) {
    this->largeur=i;
}

void GrilleElements::ajoutCaseAcces (int i, int j) {
    Element * e;
    e->setX(i);
    e->setY(j);
    // e.setTypeID(2) //en attente ajout de la méthode dans élement
    this->ajoutElement(e);    
}


int getTile (int i) {
	return 0;
}
