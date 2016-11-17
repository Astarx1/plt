#include "../ia.h"
#include "../engine.h"
#include "../state.h"

#include <string>
#include <iostream>

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
    state::Personnage* ennemi = strat.cible(id,etat);
    std::vector<int> params;
    std::string cmd;
    
    if(strat.attaqueCible(etat,id,ennemi)){
        params.push_back(id);
        int d = etat->getIdPersonnage(ennemi->getX(), ennemi->getY());
        params.push_back(d);

        cmd = "a"; // attaque CAC
    }
    else{
        std::cout << "[Warning] IAcombat::exec_cmd : PM non implementes" << std::endl;
        if(true){
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