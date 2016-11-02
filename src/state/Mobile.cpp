#include "Mobile.h"

using namespace state;

Mobile::Mobile () {
}

bool const Mobile::isStatic () {
	return true;
}

Direction Mobile::getDirection () {
	return this->direction;
}

void Mobile::setDirection (Direction d) {
    this->direction = d;
}

bool Mobile::getEnDeplacement () {
    return enDeplacement;
}

void Mobile::setEnDeplacement (bool b) {
    this->enDeplacement = b;
}

sf::Time Mobile::getTimer () {
	return this->timer;
}

void Mobile::setTimer (sf::Time timer) {
    this->timer = timer;
}

int const Mobile::getXobj () {
	return xObj;
}

void Mobile::setXobj (int x) {
	xObj = x;
}

int const Mobile::getYobj () {
	return yObj;
}

void Mobile::setYobj (int y) {
	yObj = y;
}
