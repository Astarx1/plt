#include "../engine.h"

using namespace engine;

void ListeCommandes::Ajouter (Commande cmd){
    commandes.push_back(cmd);
}

void ListeCommandes::ToutExecuter (){
    if (commandes.size() > 0){
        int i;
        for (i=0;i<commandes.size();i++){
            (commandes[i]).run();
        }
    }
}

