#include "../engine.h"
#include <vector>

using namespace std;

namespace engine{
Commande::Commande (state::Etat* e, sf::Time t, std::string cmd, int id, std::vector<int> params){
    Regles r;
    
    if (cmd =="d"){
        if (r.peutDeplacer(e,id,params[0],params[1])){
            //Deplacer d;  //changer en action changerobjectif
            std::vector<int> v;
            v.push_back(id);
            //d.run(e,v,t);
        }
    }
        
    if (cmd =="a"){ 
        if (r.peutAttaquer(e,id)){
            //Attaquer a;
            std::vector<int> v;
            v.push_back(id);
            //a.run(e,v,t);
        }
    }
        
    if (cmd =="cm"){  
        if (r.peutChangerMap(e,id)){
            ChangerMap cm;
            std::vector<int> v;
            //v.push_back(r.defCarteSuiv(e));
            cm.run(e,v,t);
        }
    }
    
    if (cmd =="qc"){ 
        if (r.peutQuitterCombat(e)){
            QuitterCombat qc;
            std::vector<int> v;
            qc.run(e,v,t);
        }
    }
    
    if (cmd =="ec"){ 
        if (r.peutEntrerCombat(e,id)){
            EntrerCombat ec;
            std::vector<int> v;
            v.push_back(id);
            v.push_back(params[0]);
            v.push_back(params[1]);
            ec.run(e,v,t);
        }
    }
    
    if (cmd =="pt"){ 
        if (r.doitPasserTour(e,id,t)){
            PasserTour passtour;
            std::vector<int> v;
            passtour.run(e,v,t);
        }
    }
            
        }
}
