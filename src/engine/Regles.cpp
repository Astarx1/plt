#include "Regles.h"


using namespace state;

namespace engine {
/*    
bool Regles::peutDeplacer (state::Etat* e, int id){
    Personnage& perso = e->getRefPersonnage(id);
    if(e->getEnCombat()){
        // Si le personnage est en combat
        if(perso.getPM() == 0){
            return false;
        }
        else if()
    }
    else{
        // Si le personnage n'est pas en combat
    }
    return true;
}
*/
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

/*Cette focntion permet de vérifier si le joueur se trouve sur une case ACCES
 *afin de pourvoir changer de carte
 */
bool Regles::peutChangerMap (state::Etat* e, int id){    
    Personnage& perso = e->getRefPersonnage(id);
    if((e->getGrille().isAcces(perso.getX(),perso.getY()))){
        return true;
    }
   
    return false;
}

};