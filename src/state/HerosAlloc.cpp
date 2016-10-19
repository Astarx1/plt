#include "HerosAlloc.h"
#include "Heros.h"
#include <iostream>
using namespace state;

HerosAlloc::HerosAlloc (int id) {
	this->id = id;
}

Element * HerosAlloc::newInstance () {
	std::cout << "HerosAlloc.cpp : Objet cree !" << std::endl;
	return new Heros(0,0,0);
}
