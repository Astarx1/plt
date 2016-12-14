#include "../server.h"

using namespace server;

CommandeService::CommandeService ():AbstractService("/commande"){

}

HttpStatus CommandeService::get (Json::Value& out, int epoque) const{
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    
}

HttpStatus CommandeService::put (Json::Value& out, const Json::Value& in){
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
}

