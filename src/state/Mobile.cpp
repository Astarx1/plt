#include "state.hpp"
#include "Mobile.h"

Mobile::Mobile () {
}

bool const Mobile::isStatic () {
	return nullptr;
}

Direction Mobile::getDirection () {
	return Direction ();
}

void Mobile::setDirection (Direction d) {
}

bool Mobile::getEnDeplacement () {
	return false;
}

void Mobile::setEnDeplacement (bool b) {
}

int Mobile::getTimer () {
	return 0;
}

void Mobile::setTimer (int timer) {
}
