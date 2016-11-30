#include "../render.h"
#include "../state.h"

using namespace render;
using namespace state;

cmdRendu::cmdRendu(state::Etat* ne, char typechang, sf::Time nt) { 
	e = ne;
	tc = typechang;
	t = nt;
}

state::Etat * cmdRendu::getEtat() { 
	return e;
}

sf::Time cmdRendu::getTime() { 
	return t;
}

char cmdRendu::getTC() { 
	return tc;
}