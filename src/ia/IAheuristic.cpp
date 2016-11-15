#include "../ia.h"
#include "../engine.h"
#include "../state.h"

using namespace state;
using namespace ia;
using namespace engine;

Personnage* IAheuristic::cible(std::vector<state::Personnage*> ennemis){
    
    Personnage* perso = ennemis[0];
    
    if(ennemis.size() > 1){
       for(int i=1; i < ennemis.size()-1; i++){
            if(perso->getVie() > ennemis[i]->getVie()){
                perso = ennemis[i];
            }
        } 
    }
   
    return perso;  
}

