#include "AccesAlloc.h"
#include "Acces.h"
using namespace state;

AccesAlloc::AccesAlloc (int id) {
}

Element * AccesAlloc::newInstance () {
	return new Acces(0,0);
}
