#include "ListeElements.h"
#include <iostream>
#include <bits/stl_vector.h>

using namespace state;

ListeElements::ListeElements () {
	factory = new ElementFactory();
}

ListeElements::~ListeElements () {
	;
}

int ListeElements::size () {
	return (this->elements).size();
}

Element * ListeElements::getElement (int n) {
	return (elements).at(n);
}

void ListeElements::setElement (int i, Element * e) {
    (this->elements).at(i) = e;
}

void ListeElements::ajoutElement (char e) {
	Element * ne = factory->newInstance(e);
	elements.push_back (ne);
}

void ListeElements::ajoutElement (Element * e) {
	elements.push_back (e);
}

bool const ListeElements::isPerso (int i, int j){
    for(size_t k=0; k < elements.size(); k++){
        if(this->getElement(k)->getX() == i && this->getElement(k)->getY() == j){
            if(this->getElement(k)->getTypeID() == PERSO || this->getElement(k)->getTypeID() == MONSTRE){
                return true;
            }
        }
    }
    
    return false;
}

Statique * ListeElements::getTile (int n) {
	// TODO: insert return statement here
	
	Element * o = getElement(n);
	
	o->accepte (visiteur);
	TypeID a = o->getTypeID();
	
	if (a == TypeID(VIDE)) 
		return (Statique *)(visiteur.getpVide ());
	else  
		return (Statique *)(visiteur.getpAcces ());
}

void ListeElements::clear() {
	elements.clear();
}
