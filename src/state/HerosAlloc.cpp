#include "state.hpp"
#include "HerosAlloc.h"

HerosAlloc::HerosAlloc (int id) {
	this->id = id;
}

Element * HerosAlloc::newInstance () {
	return new Heros(0,0,0);
}
