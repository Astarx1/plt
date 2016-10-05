#include "state.hpp"
#include "ElementFactory.h"

ElementFactory::ElementFactory () {
}

Element * ElementFactory::newInstance (char id) {
	return nullptr;
}

void ElementFactory::registerType (char id, IElementAlloc & a) {
}
