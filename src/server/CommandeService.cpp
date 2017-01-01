#include "../server.h"
#include "../engine.h"

using namespace server;
using namespace engine;
using namespace std;

CommandeService::CommandeService ():AbstractService("/commande"){

}

HttpStatus CommandeService::get (Json::Value& out, int epoque) const{
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    /*
    Commande cmd = commandes.getCommande(epoque);
    
    out["cmd"] = cmd.getType();
    out["params"] = cmd.getParams();
    out["epoque"] = epoque;
    out["perso_id"] = cmd.getId();
    */
    return OK;
    
}

HttpStatus CommandeService::put (Json::Value& out, const Json::Value& in){
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    /*Json::Value tab;
    tab = in["params"]*/
            
    string cmd = in["cmd"].asString();
    int epoque = in["epoque"].asInt();
    int id_perso = in["perso_id"].asInt();
    //vector<int> params = in["params"]
    out["epoque"] = 0;
    
    return HttpStatus::CREATED;
}

