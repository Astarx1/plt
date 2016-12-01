#include "GrilleElements.h"
#include "Statique.h"
#include "../state.h"
#include "../render.h"
#include <iostream>

#define TRACE_GRILLEELT 0

using namespace state;
using namespace render;

GrilleElements::GrilleElements (int nv,Etat* etat) : ListeElements(etat) {
    switch (nv)
    {
		case 1:
		{
			this->largeur=20;
			this->longueur=16;
		}
        break;
		case 2:
		{
			this->largeur=20;
			this->longueur=16;
		}
        break;
		case 3:
		{
			this->largeur=20;
			this->longueur=16;
		}
        break;
    }
}

int GrilleElements::getLongueur () {
	return this->longueur;
}

int GrilleElements::getLargeur () {
	return this->largeur;
}

bool const GrilleElements::isAcces (int i, int j) {
    //std::cout<<"GrilleElements::isAcces "<<this->elements.size()<<std::endl;
    for(int k=0; k < elements.size(); k++){
        if((getElement(k))->getX() == i && (getElement(k))->getY() == j){
			#if TRACE_GRILLEELT == 1
				std::cout << "GrilleElements::isAcces : On teste si " << i << ", " << j << " est un acces" <<std::endl;
			#endif
            if(this->getElement(k)->getTypeID() == TypeID(ACCES)) {
				#if TRACE_GRILLEELT == 1
					std::cout << "GrilleElements::isAcces : " << i << ", " << j << " est un acces" <<std::endl;
				#endif
                return true;
            }
        }
    }
    return false;
}

void GrilleElements::setCase (Element * e, int i, int j) {
    e->setX(i);
    e->setY(j);
}

int sup (float a) {
	int i = 0;
	while (i <= a) ++i;
	return i;
}

void GrilleElements::charger (char * nom_fichier) {
	elements.clear();
	Parseur p;
	std::vector<int> l = p.ParsingMap(nom_fichier);
	
	for (int i = 0; i < l.size(); ++i) {
		if (l[i]==12) {
			ajoutElement('a');
		}
		else{
			ajoutElement('v');
		}
		
		Statique * a = getTile(elements.size()-1);
		
		a->setTile(l[i]);
		a->setX(i%largeur+1);
		a->setY(sup(i/largeur)-1);

		#if TRACE_GRILLEELT == 1
			if (a->getTile() == 12)
				std::cout << "GrilleElements::charger : On rajoute une case acces : X(" << (elements.at(elements.size()-1))->getX() << ") Y(" << (elements.at(elements.size()-1))->getY() << ")" <<std::endl;
		#endif
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
