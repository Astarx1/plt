#include "../server.h"
#include <iostream>
#include <json/json.h>
#include <memory>


using namespace std;
using namespace server;

void ServicesManager::registerService (unique_ptr<AbstractService> service) {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    services.push_back(std::move(service));
}

AbstractService* ServicesManager::findService (const string& url) const {
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    AbstractService* ret= nullptr;
    
    for(size_t i = 0; i < services.size(); i++){
		const string& pattern = (services[i].get())->getPattern();
		if(url.find(pattern) != 0)
			continue;
		if(url.size() > pattern.size() && url[pattern.size()] != '/')
			continue;
		
		ret = services[i].get();
		
	}
	
	return ret;
}

HttpStatus ServicesManager::queryService (string& out, const string& in, const string& url, const string& method) { 
    throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    
    
}

