#include "ListeElements.h"

using namespace state;

ListeElements::ListeElements () {
}

ListeElements::~ListeElements () {
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

void ListeElements::ajoutElement (Element * e) {
	elements.push_back (e);
}

bool const ListeElements::isPerso (int i, int j) {
	return false;
}
