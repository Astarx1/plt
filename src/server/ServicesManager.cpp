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
    //throw ServiceException(HttpStatus::NOT_IMPLEMENTED,"Non implanté");
    HttpStatus stat;
    Json::Value  jsonObject_out;
    Json::Value  jsonObject_in;
    AbstractService* service;
    
    service = findService(url);
    
    // Recherche un éventuel id (ex: /mon/service/<id>)
    const string& pattern(service->getPattern());
    int id = 0;
    if (url.size() > pattern.size()) {
        string end = url.substr(pattern.size());
        if (end[0] != '/')
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        end = end.substr(1);
        if (end.empty())
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée (forme attendue: <service>/<nombre>)");
        try {
            size_t pos = 0;
            id = stoi(end,&pos);
            if (pos != end.size())
                throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
        catch(...) {
            throw ServiceException(HttpStatus::BAD_REQUEST,"Url malformée: '"+end+"' n'est pas un nombre");
        }
    }
    
    // Traite les différentes méthodes
    if( !service ){
		std::cout << "Le service demandé n'est pas défini !" << std::endl;
		throw ServiceException(HttpStatus::NOT_FOUND,"Service "+url+" non trouvé");
	}
	else{
		if(method == "GET"){
			stat = service->get(jsonObject_out,id);
			out = jsonObject_out.toStyledString();
		}
		else if(method == "POST"){
			Json::Reader jsonReader;
        
			if (!jsonReader.parse(in,jsonObject_in))
				throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
			
			stat = service->post(jsonObject_in,id);
			
		}
		else if(method == "PUT"){
			Json::Reader jsonReader;
        
			if (!jsonReader.parse(in,jsonObject_in))
				throw ServiceException(HttpStatus::BAD_REQUEST,"Données invalides: "+jsonReader.getFormattedErrorMessages());
			
			stat = service->put(jsonObject_out,jsonObject_in);
			out = jsonObject_out.toStyledString();
		}
		else if(method == "REMOVE"){
			stat = service->remove(id);
		}
		else{
			throw ServiceException(HttpStatus::BAD_REQUEST, "Requête invalide");
		}
	}
	
	
	return stat;
}

