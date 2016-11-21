#include "../engine.h"
#include "../state.h"

#include <iostream>

#define TRACE_ATTAQUER 1

using namespace engine;
using namespace state;

void Attaquer::run(Etat* e, std::vector<int> params,sf::Time t){
  	if (true) {	// Inserer ici la condition verifiant que l'on peut attaquer
        // Inserer ici la fonction pour les dégats
		int degat = 10;
		
		Personnage & attaquant = e->getRefPersonnage(params[0]);
		Personnage & attaque_subit = e->getRefPersonnage(params[1]);

  		#if TRACE_ATTAQUER==1
  			std::cout << "Attaquer::run : On attaque - " << params[0] << " (" << attaquant.getPM() << " PM) -> " << params[1] << " (" << attaque_subit.getVie() << " PV)" << std::endl;
  		#endif

		attaque_subit.setVie (attaque_subit.getVie() - degat > 0 ? attaque_subit.getVie() - degat : 0);

		if (attaque_subit.getVie() - degat <= 0) {
		    e->enleverPerso(params[1]);
		}

		// Inserer ici la fonction pour recuperer le cout en PM
		int pm = 4;
		attaquant.setPM(attaquant.getPM() - pm);

  		#if TRACE_ATTAQUER==1
  			std::cout << "Attaquer::run : Resultat - " << params[0] << " : " << attaquant.getPM() << " PM -> " << params[1] << " : " << attaque_subit.getVie() << " PV" << std::endl;
  		#endif
	}
}
