#include "Regles.h"


using namespace state;

namespace engine {
    
bool Regles::peutDeplacer (state::Etat* e, int id){
    // à comléter
    return true;
}

/* Cette fonction permet de vérifier si un personnage de type Heros peut entrer
 * en combat. 
 */
bool Regles::peutEntrerCombat (state::Etat* e, int id){
    Personnage& perso = e->getRefPersonnage(id);
    if(perso.isJoueur()){
        if(e->getEnCombat() == false){
            return true;
        }
    }
    else{
        return false;
    }
}

bool Regles::peutChangerMap (state::Etat* e, int id){
    return false;
}

};