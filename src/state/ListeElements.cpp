#include "ListeElements.h"
#include <iostream>

using namespace state;

ListeElements::ListeElements () {
	factory = new ElementFactory();
	std::cout << "ListeElements.cpp - constructeur : Factory cree !" << std::endl;
}

ListeElements::~ListeElements () {
	;
}

int ListeElements::size () {
	return (this->elements).size();
}

Element * ListeElements::getElement (int n) {
	return this->elements[n];
}

void ListeElements::setElement (int i, Element * e) {
    this->elements[i] = e;
}

void ListeElements::ajoutElement (char e) {
	Element * ne = factory->newInstance(e);
	elements.push_back (ne);
	std::cout << "ListeElements.cpp - ajoutELement : Element cree ! Type : " << ne->getTypeID() << std::endl;
}

void ListeElements::ajoutElement (Element * e) {
	elements.push_back (e);
}

bool const ListeElements::isPerso (int i, int j) {
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
