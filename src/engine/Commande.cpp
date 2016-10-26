#include "../engine.h"
#include <vector>
#include <iostream>

using namespace std;

namespace engine{
void Commande::run (){
    Regles r;
    
    if (type =="d"){
        std::cout<< "il peut se d "<< r.peutDeplacer(etat,id,params[0],params[1]);
        if (r.peutDeplacer(etat,id,params[0],params[1])){
            std::cout<< "deb";
            ChangerObjectif cb;  //changer en action changerobjectif
            Deplacer d;
            std::vector<int> v;
            v.push_back(id);
            cb.run(etat,v,temps);
            //v.clear();
            d.run(etat,v,temps);
        }
    }
        
    if (type =="a"){ 
        if (r.peutAttaquer(etat,id)){
            Attaquer a;
            std::vector<int> v;
            v.push_back(id);
            a.run(etat,v,temps);
        }
    }
        
    if (type =="cm"){  
        if (r.peutChangerMap(etat,id)){
            ChangerMap cm;
            std::vector<int> v;
            //v.push_back(r.defCarteSuiv(etat));
            cm.run(etat,v,temps);
        }
    }
    
    if (type =="qc"){ 
        if (r.peutQuitterCombat(etat)){
            QuitterCombat qc;
            std::vector<int> v;
            qc.run(etat,v,temps);
        }
    }
    
    if (type =="ec"){ 
        if (r.peutEntrerCombat(etat,id)){
            EntrerCombat ec;
            std::vector<int> v;
            v.push_back(id);
            v.push_back(params[0]);
            v.push_back(params[1]);
            ec.run(etat,v,temps);
        }
    }
    
    if (type =="pt"){ 
        if (r.doitPasserTour(etat,id,temps)){
            PasserTour passtour;
            std::vector<int> v;
            passtour.run(etat,v,temps);
        }
    }
            
}

Commande::Commande (state::Etat* e,std::string type, sf::Time t, std::vector<int> params,int id){
    etat=e;
    temps=t;
    this->type=type;
    this->params=params;
    this->id=id;
}
Commande::~Commande(){
    
}

std::string const Commande::getType (){
    return type;
}

void Commande::setType (std::string cmd){
    type=cmd;
}
}
