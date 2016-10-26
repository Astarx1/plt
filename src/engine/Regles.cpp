#include "../engine.h"


using namespace state;
using namespace sf;


namespace engine {

/* Cette fonction permet de vérifier si le joueur peut se déplacer à la nouvelle
 * position (newX,newY)
 * 
 * À compléter!!!
 */   
bool Regles::peutDeplacer(state::Etat* e, int id, int newX, int newY){
    Personnage& perso = e->getRefPersonnage(id);
    if(e->getEnCombat()){
        // Si le personnage est en combat
        if(perso.getPM() == 0){
            return false;
        }
        else if(!(e->getPerso()).isPerso(newX,newY)){
            return false;
            // Penser au cas en réseau où il peut y avoir d'autre héros
        }
    }
    else{
        // Si le personnage n'est pas en combat
        if(newY < 100 ){
            // Seuil à ajuster!
            return false;
        }
    }
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

/*Cette fonction permet de vérifier si le joueur se trouve sur une case ACCES
 *afin de pourvoir changer de carte
 */
bool Regles::peutChangerMap (state::Etat* e, int id){    
    Personnage& perso = e->getRefPersonnage(id);
    if((e->getGrille().isAcces(perso.getX(),perso.getY()))){
        return true;
    }
   
    return false;
}

/* Cette fonction permet de vérifier s'il est possible de quitter le mode combat.
 */
bool Regles::peutQuitterCombat(state::Etat* e){
    bool retH = false;
    bool retM = false;
    ListeElements persos = e->getPerso();
    
    for(size_t i=0; persos.size(); i++){
        if(e->getRefPersonnage(i).getTypeID() == HEROS && e->getRefPersonnage(i).getVie() >0){
            retH = true;
        }
        if(e->getRefPersonnage(i).getTypeID() == MONSTRE && e->getRefPersonnage(i).getVie() >0){
            retM = true;
        }
    }
    return !(retH && retM);
        
}

bool Regles::peutAttaquer(state::Etat* e, int id){
    Personnage& perso = e->getRefPersonnage(id);
    
    if(e->getEnCombat()){
        if(perso.getPA() > 0){
            return true;
        }
    }
    else{
        return false;
    }
}

bool Regles::doitPasserTour(state::Etat* e, int id, sf::Time t){
    Combat& combat = e->getRefCombat();
    Time timeDeb = combat.getTimerDebutTour();
    if((t.asSeconds()- timeDeb.asSeconds()) >= 60){
        return true;
    }
    return false;
}

bool Regles::peutAccederMenu(state::Etat* e){
    if(e->getEnCombat()){
        return false;
    }
    else{
        return false;
    }
}

bool Regles::peutAccederInfoPerso(state::Etat* e){
    if(e->getEnCombat()){
        return false;
    }
    else{
        return false;
    }
}

bool Regles::peutAugmenterNiv(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    int exp = 0; // À COMPLÉTER
    
    if(exp >= nv*100){
        return true;
    }
    
    return false;      
    
}
};