#include "state.hpp"
#include "Mobile.h"

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
    if(this->enDeplacement == true)
	return true;
    else 
        return false;
}

void Mobile::setEnDeplacement (bool b) {
    this->enDeplacement = b;
}

int Mobile::getTimer () {
	return this->timer;
}

void Mobile::setTimer (int timer) {
    this->timer = timer;
}
