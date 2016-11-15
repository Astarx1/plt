#include "HerosAlloc.h"
#include "Heros.h"
#include <iostream>
using namespace state;

HerosAlloc::HerosAlloc (int id) {
	this->id = id;
}

Element * HerosAlloc::newInstance () {
	return new Heros(0,0,0);
}
