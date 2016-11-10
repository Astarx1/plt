#include "../ia.h"
#include "../engine.h"
#include "../state.h"

using namespace state;
using namespace ia;
using namespace engine;

IAminimale::IAminimale(state::Etat* etat){
    this->etat = etat;
}

IAminimale::~IAminimale(){

}

Commande IAminimale::exec_cmd(int id, sf::Time time){
    Personnage& perso = this->etat->getRefPersonnage(id);
    
    std::vector<int> params;
    if(!perso.getEnDeplacement()){
        params[0]= rand()%20 +1;
        params[1]= rand()%12 +1;
    }
    
    Commande c(etat, "d" ,time,params,id);
    return c;
}
