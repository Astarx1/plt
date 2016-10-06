#include "state.hpp"
#include "MonstreAlloc.h"

MonstreAlloc::MonstreAlloc (int id) {
}

Element * MonstreAlloc::newInstance () {
	return new Monstre(0,0,0);
}
