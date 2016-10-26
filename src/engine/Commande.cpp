#include "../engine.h"
#include <vector>

using namespace std;

namespace engine{
Commande::Commande (state::Etat* e, sf::Clock cl, std::string cmd, int id, std::vector<int> params){
    Regles r;
    std::vector<int> v;
    if (cmd =="d"){
        if (r.peutDeplacer(e,id,params[0],params[1])){
            Deplacer d;
            v.push_back(id);
            d.run(e,v);
        }
            
        }
}
}
