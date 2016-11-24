#include "../ia.h"

#define PROFONDEUR_ARBRE 10

using namespace ia;

engine::Commande MinMaxIA::exec_cmd (int id, sf::Time time) {
	tmp_arbre.creerArbre(etat->getPerso(), PROFONDEUR_ARBRE);
}