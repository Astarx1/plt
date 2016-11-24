#include "../ia.h"
#include "../state.h"

using namespace state;
using namespace ia;

Noeud::Noeud (Noeud * npere, int nid, state::Element * lien) : pere(npere), lien(lien), id(nid) { ; }
Noeud::~Noeud () { ; }
void Noeud::createFils (state::ListeElements& lp, int p) {
	for (int i = 0; i < lp.size(); ++i) {
		fils.push_back(new Noeud (this, i, lp.getElement(i)));
		if (p > 0)
			(fils[fils.size()-1])->createFils(lp, p-1);
	}
}
void Noeud::setF (float nf) {
	f = nf;
}
float Noeud::getF () {
	return f;
}
int Noeud::getID () {
	return id;
}
state::Element * Noeud::getLien () {
	return lien;
}