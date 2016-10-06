#include "state.hpp"
#include <assert.h>
#include <map>
#include "ElementFactory.h"

ElementFactory::ElementFactory () {
	ElementFactory::id = 0;
	
	IElementAlloc * hp = new HerosAlloc (1);
	liste.insert( std::map <char, IElementAlloc * >('h',  hp) );
	
	IElementAlloc * mp = new MonstreAlloc (2);
	liste.insert( std::map <char, IElementAlloc * >('m',  mp) );
	
	IElementAlloc * vp = new VideAlloc (3);
	liste.insert( std::map <char, IElementAlloc * >('v',  vp) );
	
	IElementAlloc * ap = new AccesAlloc (4);
	liste.insert( std::map <char, IElementAlloc * >('a',  ap) );
}

Element * ElementFactory::newInstance (char id) {
	assert(id == 'h' || id == 'm' || id == 'v' || id = 'a');
	
	Element * t = (liste[id])->newInstance();
	(ElementFactory::id)++;
	t->setElemID(ElementFactory::id);
	return t;
}

void ElementFactory::registerType (char id, IElementAlloc & a) {
	// Invalide
}
