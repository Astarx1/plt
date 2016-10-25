#include "../engine.h"
#include "../state.h"

using namespace engine;
using namespace state;

void Attaquer::run(Etat* e, std::vector<int> params){
  	if (true) {	// Inserer ici la condition verifiant que l'on peut attaquer
        // Inserer ici la fonction pour les dégats
		int degat = 0;

		Personnage & attaque_subit = e->getRefPersonnage(params[1]);
		attaque_subit.setVie (attaque_subit.getVie() - degat > 0 ? attaque_subit.getVie() - degat : 0);
		if (attaque_subit.getVie() - degat <= 0) {
		    e->enleverPerso(params[1]);
		}
		// Inserer ici la fonction pour recuperer le cout en PM
		int pm = 0;
		Personnage & attaquant = e->getRefPersonnage(params[0]);
		attaquant.setPM(attaquant.getPM() - pm);
	}
}
