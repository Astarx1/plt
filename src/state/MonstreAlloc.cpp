#include "MonstreAlloc.h"
#include "Monstre.h"
using namespace state;

MonstreAlloc::MonstreAlloc (int id) {
}

Element * MonstreAlloc::newInstance () {
	return new Monstre(0,0,0);
}
