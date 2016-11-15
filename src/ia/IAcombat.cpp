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
    std::vector<int> params;
    params.resize(2);
    
    Commande c(etat, "d" ,time,params,id);
    return c;
}