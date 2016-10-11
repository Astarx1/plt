#include <assert.h>
#include <map>
#include "ElementFactory.h"
#include "HerosAlloc.h"
#include "MonstreAlloc.h"
#include "VideAlloc.h"
#include "AccesAlloc.h"
#include "Element.h"

using namespace state;

ElementFactory::ElementFactory () {
	id = 0;
	
	IElementAlloc * hp = new HerosAlloc (1);
	liste.insert( std::pair <char, IElementAlloc * >('h',  hp) );
	
	IElementAlloc * mp = new MonstreAlloc (2);
	liste.insert( std::pair <char, IElementAlloc * >('m',  mp) );
	
	IElementAlloc * vp = new VideAlloc (3);
	liste.insert( std::pair <char, IElementAlloc * >('v',  vp) );
	
	IElementAlloc * ap = new AccesAlloc (4);
	liste.insert( std::pair <char, IElementAlloc * >('a',  ap) );
}

Element * ElementFactory::newInstance (char cid) {
	assert(cid == 'h' || cid == 'm' || cid == 'v' || cid = 'a');
	
	Element * t = (liste[id])->newInstance();
	(id)++;
	t->setElemID(id);
	return t;
}

void ElementFactory::registerType (char id, IElementAlloc & a) {
	// Invalide
}
