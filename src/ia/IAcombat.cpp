#include "../ia.h"
#include "../engine.h"
#include "../state.h"

#include <string>

using namespace ia;
using namespace state;
using namespace engine;

IAcombat::IAcombat(state::Etat* etat){
    this->etat = etat;
}

IAcombat::IAcombat(){

}

IAheuristic IAcombat::getIAheuristic(){
    return this->strat;
}

Commande IAcombat::exec_cmd(int id, sf::Time time){
    state::Etat* etat = etat;
    state::Personnage* ennemi = strat.cible(id,etat);
    std::vector<int> params;
    std::string cmd;
    
    if(strat.attaqueCible(etat,id,ennemi)){
        params.push_back(id);
        params.push_back(ennemi->getElemID());
        cmd = "a"; // attaque CAC
    }
    else{
        if(etat->getRefPersonnage(id).getPM() != 0){
            params = strat.posCible(etat,id,ennemi);
            cmd = "d";
        }
        else{
            params.push_back(id);
            params.push_back(ennemi->getElemID());
            cmd = "a"; // attaque à distance
        }
    }
    
    Commande c(etat, cmd,time,params,id);
    return c;
}