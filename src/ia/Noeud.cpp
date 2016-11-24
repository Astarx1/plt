#include "../ia.h"
#include "../state.h"

#include <algorithm>

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

Noeud * Noeud::getPere() {
	return pere;
}

state::Element * Noeud::MinMax (bool heros) {
	if (fils.size() > 0) {
		for (int i = 0; i < fils.size(); ++i) {
			if (fils[i] != nullptr) {
				(fils[i])->MinMax(heros);
			}
		}
	}
	else {
		std::vector<Noeud *> ids;
		Noeud * t = p;

		while (t->getPere != nullptr) {
			ids.push_back(t);
			t = t->getPere();
		}
		
		std::vector<int> morts;
		for (int i = 0; i < ids.size(); ++i) {
			std::vector <int> pos; 
			for (int j = ids.size() - 1; j > 0 ; j--) {
				if (ids[j].getID() == ids[i].getID())
					pos.push_back(j);
			}
			if (pos.size() > 1) {
				morts.push_back(i);
				for (int j = 1; j < pos.size(); ++j) {
					ids.erase(ids.begin() + pos[j]);
				}
			}
		}

		for (int i = 0; i < morts.size(); ++i) {
			getTypeID
		}
	}
}