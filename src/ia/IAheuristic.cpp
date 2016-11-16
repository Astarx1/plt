#include "../ia.h"
#include "../engine.h"
#include "../state.h"

using namespace state;
using namespace ia;
using namespace engine;
using namespace std;

Personnage* IAheuristic::cible(std::vector<state::Personnage*> ennemis, int id, state::Etat* etat){
    
    Personnage* perso = ennemis[0];
    std::vector< state::Personnage* > cibles;
    std::vector<int> pos_ennemi, pos_joueur, pos_cible;
    pos_ennemi.resize(2);
    pos_joueur.resize(2);
    pos_cible.resize(2);
    int dmin = 0, index = 0;
    
    pos_joueur[0] = etat->getRefPersonnage(id).getX();
    pos_joueur[1] = etat->getRefPersonnage(id).getY();
    
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

