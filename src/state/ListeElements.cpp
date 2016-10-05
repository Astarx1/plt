#include "state.hpp"
#include "ListeElements.h"

ListeElements::ListeElements () {
}

ListeElements::~ListeElements () {
}

int ListeElements::size () {
	return 0;
}

Element * ListeElements::getElement (int n) {
	return nullptr;
}

void ListeElements::setElement (int i, Element * e) {
}

void ListeElements::ajoutElement (Element * e) {
	elements.push_back (e);
}

bool const ListeElements::isPerso (int i, int j) {
	return nullptr;
}
