#include "Element.h"

using namespace state;

Element::Element () {
    //à voir si on laisse vide
}

Element::~Element () {
}

int Element::getX () {
	return this->x;
}

int Element::getY () {
	return this->y;
}

void Element::setX (int const x) {
	this->x=x;
}

void Element::setY (int const y) {
    this->y=y;
}

int Element::getElemID () {
	return this->elemID;
}

void Element::setElemID (int i) {
    this->elemID=i;
}
