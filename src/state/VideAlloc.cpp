#include "VideAlloc.h"
#include "Vide.h"

using namespace state;

VideAlloc::VideAlloc (int id) {
}

Element * VideAlloc::newInstance () {
	return new Vide(0,0);
}
