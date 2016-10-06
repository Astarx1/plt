#include "state.hpp"
#include "VideAlloc.h"

VideAlloc::VideAlloc (int id) {
}

Element * VideAlloc::newInstance () {
	return new Vide(0,0);
}
