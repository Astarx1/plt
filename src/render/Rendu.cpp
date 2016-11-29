#include "Rendu.h"
#include <iostream>

using namespace render;
using namespace state;

void Rendu::run (Etat* e, sf::RenderWindow& sw, sf::Time cl, sf::RenderStates rs) {
	rg.dessin(sw, e);
	rp.dessin(sw, e, 0, cl, rs);
}

Rendu::Rendu () {  
}

void Rendu::maj(state::Etat* e, char typechang){
    if(typechang == 'g'){
        rg.testChgtMap(e);
        
    }
    else if(typechang == 'p'){
        
    }
    else{
        std::cout<<"[Warning] Rendu::maj: Cette mise à jour n'est pas définie"<<std::endl;
    }
}