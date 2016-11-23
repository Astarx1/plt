#include "../engine.h"
#include <iostream>

#define TRACE_LC 1

using namespace engine;
using namespace std;

void ListeCommandes::Ajouter (Commande cmd){
    commandes.push_back(cmd);
}

void ListeCommandes::ToutExecuter (){
    if (commandes.size() > 0){
        unsigned int i;
        for (i=0;i<commandes.size();i++){
            (commandes[i]).run();
            if (commandes[i].getType() == "cm" || commandes[i].getType() == "ec") {
        		commandes.clear();
            	#if TRACE_LC == 1
        		std:: cout << "ListeCommandes::ToutExecuter : On a clear les commandes " << std::endl;
        		#endif
        				
        		break;
            }
        }
        commandes.clear();
    }
}

