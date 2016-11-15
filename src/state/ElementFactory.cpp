#include <assert.h>
#include <map>
#include <iostream>
#include "ElementFactory.h"
#include "HerosAlloc.h"
#include "MonstreAlloc.h"
#include "VideAlloc.h"
#include "AccesAlloc.h"
#include "Element.h"

#define TRACE_ELEMFACT 0
using namespace state;

ElementFactory::ElementFactory () {
	id = 0;
	
	IElementAlloc * hp = new HerosAlloc (1);
	liste.insert( std::make_pair ('h',  hp) );
	
	IElementAlloc * mp = new MonstreAlloc (2);
	liste.insert( std::make_pair ('m',  mp) );
	
	IElementAlloc * vp = new VideAlloc (3);
	liste.insert( std::make_pair ('v',  vp) );
	
	IElementAlloc * ap = new AccesAlloc (4);
	liste.insert( std::make_pair ('a',  ap) );
}

ElementFactory::~ElementFactory () {
	for(auto itr = liste.begin(); itr != liste.end(); itr++) {
	        delete itr->second;
	}
}

Element * ElementFactory::newInstance (char cid) {
	if(cid == 'h' || cid == 'm' || cid == 'v' || cid == 'a') {
		#if TRACE_ELEMFACT==1
			if (cid != 'v')
				std::cout << "ElementFactory.cpp : Demande de création d'objet : " << cid << std::endl;
		#endif
		Element * t = (liste[cid])->newInstance();
		(id)++;
		t->setElemID(id);
		return t;
	}
	#if TRACE_ELEMFACT==1
	else {
		std::cout << "ElementFactory.cpp : Demande de creation d'objet inconnu !" << std::endl;
	}
	#endif	
}

void ElementFactory::registerType (char id, IElementAlloc & a) {
	// Invalide
}
