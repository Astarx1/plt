#include "../ia.h"
#include "../state.h"

#include <algorithm>
#include <iostream>

#define INF 10000

using namespace state;
using namespace ia;

Noeud::Noeud (Noeud * npere, int nid, state::Element * lien) : pere(npere), lien(lien), id(nid) { ; }

Noeud::~Noeud () { 
	for (int i = 0; i < fils.size(); ++i) delete fils[i]; 
}

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

int Noeud::MinMax (bool heros) {
	if (fils.size() > 0) {
		int id;
		bool first = true;
		for (int i = 0; i < fils.size(); ++i) {
			if (fils[i] != nullptr) {
				(fils[i])->MinMax(heros);
				
				if (first){
					first = false;
					id = i;
					f = (fils[i])->getF();
				}
				else {
					TypeID tid = lien->getTypeID();

					if ((heros && tid == TypeID(PERSO)) || (!heros && tid == TypeID(MONSTRE))) {
						if (f > (fils[i])->getF()) {
							id = i;
							f = (fils[i])->getF();
						}
					}
					else {
						if (f < (fils[i])->getF()) {
							id = i;
							f = (fils[i])->getF();
						}					
					}	
				}	
			}
		}
		return id;
	}
	else {
		std::vector<Noeud *> ids;
		ids.push_back(this);

		Noeud * t = pere;

		while (t->getPere() != nullptr) {
			ids.push_back(t);
			t = t->getPere();
		}
		
		std::vector<int> morts;
		for (int i = 0; i < ids.size(); ++i) {
			std::vector <int> pos; 
			for (int j = ids.size() - 1; j > 0 ; j--) {
				if (ids[j]->getID() == ids[i]->getID())
					pos.push_back(j);
			}

			if (pos.size() > 1) {
				if ((std::count (morts.begin(), morts.end(), ids[i]->getID()) == 0) || morts.size() == 0)
					morts.push_back(ids[i]->getID());
			}
		}
		
		f = 0;

		for (int i = 0; i < morts.size(); ++i) {
			TypeID tid = ((ids[morts[i]])->getLien())->getTypeID();
			if (tid == TypeID(PERSO)) {
				if (heros)
					f = f-20;
				else
					f = f + 40;
			}
			else {
				if (heros)
					f = f + 40;
				else
					f = f - 20;
			}
		}
		return -1;
	}
}