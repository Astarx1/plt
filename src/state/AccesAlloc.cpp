#include "state.hpp"
#include "AccesAlloc.h"

AccesAlloc::AccesAlloc (int id) {
}

Element * AccesAlloc::newInstance () {
	return new Acces(0,0);
}
