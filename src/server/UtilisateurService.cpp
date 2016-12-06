#include "../server.h"

using namespace server;


UtilisateurService::UtilisateurService ():AbstractService("/user"){

}

HttpStatus UtilisateurService::put (Json::Value& out, const Json::Value& in){
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");

}

HttpStatus UtilisateurService::remove (int id){
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");

}

