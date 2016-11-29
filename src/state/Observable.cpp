#include "../state.h"

namespace state {

    Observable::~Observable() {
	
    }

    void Observable::notifyObserver (char typeChg, sf::Time time ) { }
    
    void Observable::registerObserver(Observer *obs){
		observers.push_back(obs);
    }
}