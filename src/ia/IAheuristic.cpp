#include "../ia.h"
#include "../engine.h"
#include "../state.h"

using namespace state;
using namespace ia;
using namespace engine;
using namespace std;

Personnage* IAheuristic::cible(std::vector<state::Personnage*> ennemis){
    
    Personnage* perso = ennemis[0];
    std::vector< state::Personnage* > cibles;
    
    cibles.push_back(perso);
    
    if(ennemis.size() > 1){
       for(int i=1; i < ennemis.size()-1; i++){
            if(perso->getVie() == ennemis[i]->getVie()){
                cibles.push_back(ennemis[i]);
            }
            else if(perso->getVie() > ennemis[i]->getVie()){
                cibles.clear();
                perso = ennemis[i];
                cibles.push_back(perso);
            }
        }
       /*
       if(cibles.size()>1){
           perso = cibles.pop_back();
       }
       else{
           perso = cibles.pop_back();
       }*/
    }
   
    return perso;  
}

