#include "../server.h"
#include "../state.h"

using namespace server;
using namespace state;


UtilisateurService::UtilisateurService ():AbstractService("/connexion"){

}

HttpStatus UtilisateurService::put (Json::Value& out, const Json::Value& in){
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    bool gender = in["male"].asBool();
    
    etat->rajouterPerso('h');
    Personnage &p = etat->getRefPersonnage(etat->getPersoSize()-1);
    
    if(gender)
        p.setTypePersonnage(HEROS);
    else
        p.setTypePersonnage(HEROINE);
    
    out["id_perso"] = etat->getPersoSize()-1;
    
    return HttpStatus::CREATED;
    

}

HttpStatus UtilisateurService::remove (int id){
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    Personnage &p = etat->getRefPersonnage(id);
    /*if (!p)
        throw ServiceException(HttpStatus::NOT_FOUND,"Invalid user id");*/
    
    etat->getPerso().eraseElem(id);
    
    return HttpStatus::NO_CONTENT;

}

