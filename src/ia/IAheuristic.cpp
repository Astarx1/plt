#include <vector>
#include "../ia.h"
#include "../engine.h"
#include "../state.h"
#include "state/Personnage.h"

using namespace state;
using namespace ia;
using namespace engine;
using namespace std;

Personnage* IAheuristic::cible(int id, state::Etat* etat){
    
    std::vector< state::Personnage* > cibles, ennemis;
    Personnage* perso, *ite;
    std::vector<int> pos_ennemi, pos_joueur, pos_cible;
    int dmin = 0, index = 0;
    
    pos_ennemi.resize(2);
    pos_joueur.resize(2);
    pos_cible.resize(2);
    
    pos_joueur[0] = etat->getRefPersonnage(id).getX();
    pos_joueur[1] = etat->getRefPersonnage(id).getY();
    
    // Création de la liste d'ennemis
    for(int i=0; i < etat->getPerso().size(); i++){
        ite = &(etat->getRefPersonnage(etat->getPerso().getElement(i)->getElemID()));
        if(ite->getTypeID() == PERSO){
            ennemis.push_back(ite);
        }
        
    }
    
    perso = ennemis[0];
    cibles.push_back(perso);
    
    
    if(ennemis.size() > 1){
       // Cible l'ennemi le ayant le moins de PV
        for(int i=1; i < ennemis.size()-1; i++){
            if(perso->getVie() == ennemis[i]->getVie()){
                cibles.push_back(ennemis[i]);
            }
            else if(perso->getVie() > ennemis[i]->getVie()){
                cibles.clear();
                perso = ennemis[i];
                cibles.push_back(perso);
            }
        }
      // Si plusieurs ennemis possèdent le même PV min, alors on cible le plus proche
       if(cibles.size()>1){
           pos_ennemi[0] = cibles.at(0)->getX();
           pos_ennemi[1] = cibles.at(0)->getY();
           dmin = sqrt(pow(pos_ennemi[0]-pos_joueur[0],2)+pow(pos_ennemi[1]-pos_joueur[1],2));
           
           for(int i=1; i < cibles.size()-1; i++){
              pos_ennemi[0] = cibles.at(i)->getX();
              pos_ennemi[1] = cibles.at(i)->getY();
              
              int tmp = sqrt(pow(pos_ennemi[0]-pos_joueur[0],2)+pow(pos_ennemi[1]-pos_joueur[1],2));
              
              if(tmp < dmin){
                  dmin = tmp;
                  index = i;
              }
           }
           perso = cibles.at(index);
       }
       else{
           perso = cibles.at(0);
       }
    }
   
    return perso;  
}

std::vector<int> IAheuristic::posCible(state::Etat* etat, int id, state::Personnage* ennemi){
    std::vector<int> pos_cible, pos_ennemi, pos_joueur;
    int pm = etat->getRefPersonnage(id).getPM();
    
    pos_ennemi.resize(2);
    pos_ennemi[0] = ennemi->getX();
    pos_ennemi[1] = ennemi->getY();
    
    pos_joueur.resize(2);
    pos_joueur[0] = etat->getRefPersonnage(id).getX();
    pos_joueur[1] = etat->getRefPersonnage(id).getY();
    
    pos_cible.resize(2);
    
    while(pm != 0){
        if(pos_joueur[0] == pos_ennemi[0] && pos_joueur[1] != pos_ennemi[1]){
            if(pos_joueur[1] < pos_ennemi[1] && pos_joueur[1] != pos_ennemi[1]-1){
                pos_joueur[1]++;
                pm--;
            }
            else if(pos_joueur[1] > pos_ennemi[1] && pos_joueur[1] != pos_ennemi[1]+1){
                pos_joueur[1]--;
                pm--;
            }
            else{
                break;
            }
        }
        else if(pos_joueur[1] == pos_ennemi[1] && pos_joueur[0] != pos_ennemi[0]){
            if(pos_joueur[0] < pos_ennemi[0] && pos_joueur[0] != pos_ennemi[0]-1){
                pos_joueur[0]++;
                pm--;
            }
            else if(pos_joueur[0] > pos_ennemi[0] && pos_joueur[0] != pos_ennemi[0]+1){
                pos_joueur[0]--;
                pm--;
            }
            else{
                break;
            }
        }
        else{
            if(pos_joueur[0] < pos_ennemi[0] && pos_joueur[0] != pos_ennemi[0]-1){
                pos_joueur[0]++;
                pm--;
            }
            else if(pos_joueur[0] > pos_ennemi[0] && pos_joueur[0] != pos_ennemi[0]+1){
                pos_joueur[0]--;
                pm--;
            }
        }
    }
    
    pos_cible = pos_joueur;
    
    return pos_cible;
    
}

bool IAheuristic::attaqueCible(state::Etat* etat, int id, state::Personnage* ennemi){
    bool ret = false;
    std::vector<int> pos_ennemi, pos_joueur;
    int dist = 0;
    
    pos_ennemi.resize(2);
    pos_ennemi[0] = ennemi->getX();
    pos_ennemi[1] = ennemi->getY();
    
    pos_joueur.resize(2);
    pos_joueur[0] = etat->getRefPersonnage(id).getX();
    pos_joueur[1] = etat->getRefPersonnage(id).getY();
    
    dist = sqrt(pow(pos_ennemi[0]-pos_joueur[0],2)+pow(pos_ennemi[1]-pos_joueur[1],2));
    
    if(dist == 1){
        ret = true;
    }
    else{
        ret = false;
    }
    
    return ret;
}