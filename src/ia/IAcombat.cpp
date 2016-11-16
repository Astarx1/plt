#include "../ia.h"
#include "../engine.h"
#include "../state.h"

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
    state::Etat* etat = this->etat;
    state::Personnage* ennemi = this->strat.cible(id,etat);
    std::vector<int> params;
    params.resize(2);
    //Commande cmd;
    /*
    if(this->strat.attaqueCible(etat,id,ennemi)){
        params[0] = id;
        params[1] = ennemi->getElemID();
        Commande c(etat, "a", time, params, id);
        cmd = c;
    }*/
    
    Commande c(etat, "d" ,time,params,id);
    return c;
}