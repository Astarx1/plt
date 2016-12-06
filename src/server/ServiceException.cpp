#include "ServiceException.h"
#include <stdexcept>
#include <string>
#include "../server.h"


using namespace std;
using namespace server;

ServiceException::ServiceException (HttpStatus status, string msg) 
    : httpStatus(status),msg(msg) {    
}

HttpStatus ServiceException::status () const {
    return httpStatus;
}

const char* ServiceException::what () const {
    return msg.c_str();
}

