#include "Statique.h"

using namespace state;

Statique::Statique () {
}

bool Statique::isStatic () {
	return true;
}

int Statique::getTile () {
	return tile;
}

void Statique::setTile (int i) {
	tile = i;
}
