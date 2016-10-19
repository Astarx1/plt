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
	elements.push_back (factory->newInstance(e));
	std::cout << "ListeElements.cpp - ajoutELement : Element cree !" << std::endl;
}

void ListeElements::ajoutElement (Element * e) {
	elements.push_back (e);
}

bool const ListeElements::isPerso (int i, int j) {
	return false;
}
