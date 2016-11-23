#include "../engine.h"
#include <vector>
#include <iostream>

#define TRACE_COMMANDE 0

using namespace std;

namespace engine {

int approx (float a) {
  int i = 0;
  while (i < a) i++;
  if (i-a<=0.5) return i;
  if (i-a>0.5) return i-1;
}

void Commande::run (){
    Regles r;
    
    if (type =="d"){
        if (r.peutDeplacer(etat,id,params[0],params[1])){ 
            ChangerObjectif cb; 
            std::vector<int> v;
            v.push_back(id);
            v.push_back(params[0]);
            v.push_back(params[1]);
            cb.run(etat,v,temps);
            //v.clear(); 
        }
    }
        
    else if (type =="a"){ 
        if (r.peutAttaquer(etat,id)){
            Attaquer a;
            std::vector<int> v;
            v.push_back(id);
            v.push_back(params[1]);
            a.run(etat,v,temps);
        }
    }
        
    else if (type =="cm"){  
        if (r.peutChangerMap(etat,id)){
            #if TRACE_COMMANDE==1
                std::cout << "Commande::run : Execution de la commande ChangerMap" << std::endl;
            #endif
            ChangerMap cm;
            std::vector<int> v;
            if (params.size() > 0) {
                v.push_back(params[0]);	
            }
            else {
                v.push_back(r.defCarteSuiv(etat, id));
            } 
            cm.run(etat,v,temps);
        }
    }
       
    else if (type =="im"){  
        if (true){
            #if TRACE_COMMANDE==1
                std::cout << "Commande::run : Execution de la commande ChangerMap" << std::endl;
            #endif
            ChangerMap cm;
            std::vector<int> v;
            if (params.size() > 0) {
                v.push_back(params[0]); 
            }
            else {
                v.push_back(r.defCarteSuiv(etat, id));
            } 
            cm.run(etat,v,temps);
        }
    }

    else if (type =="qc"){ 
        if (r.peutQuitterCombat(etat)){
            QuitterCombat qc;
            std::vector<int> v;
            qc.run(etat,v,temps);
        }
    }
    
    else if (type =="ec"){ 
        if (r.peutEntrerCombat(etat,id)){
            EntrerCombat ec;
            std::vector<int> v;
            v.push_back(id);
            ec.run(etat,v,temps);
        }
    }
    
    else if (type =="pt"){ 
        if (r.doitPasserTour(etat,id,temps)){
            PasserTour passtour;
            std::vector<int> v;
            passtour.run(etat,v,temps);
        }
    }
    
    else if (type =="u"){
        Deplacer d;
        std::vector<int> v;
        v.push_back(id);
        d.run(etat,v,temps); 

        
        if (etat->getEnCombat()) {
            sf::Time tps_combat = (etat->getRefCombat()).getTimerDebutTour();
            int s = approx(temps.asSeconds() - tps_combat.asSeconds());
            if (s == 5) {
                (etat->getRefCombat()).tourSuivant(temps);
                #if TRACE_COMMANDE==1
                   std::cout << "Commande::run : Changement de tour (" << (etat->getRefCombat()).getTour() << std::endl;
                #endif       
            }
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
