// Generated by dia2code
#ifndef SERVER__COMMANDESERVICE__H
#define SERVER__COMMANDESERVICE__H

#include <json/json.h>
namespace server {
  class AbstractService;
}

#include "HttpStatus.h"
#include "AbstractService.h"

namespace server {

  /// class CommandeService - 
  class CommandeService : public server::AbstractService {
    // Operations
  public:
    CommandeService ();
    HttpStatus get (Json::Value& out, int id) const;
    HttpStatus put (Json::Value& out, const Json::Value& in);
  };

};

#endif