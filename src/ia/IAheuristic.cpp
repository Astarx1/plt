#include <vector>
#include "../ia.h"
#include "../engine.h"
#include "../state.h"

#include <iostream>

using namespace state;
using namespace ia;
using namespace engine;
using namespace std;

#define INF 100000;

Personnage* IAheuristic::cible(int id, state::Etat* etat){
    sf::Vector2f pos_ennemi, pos_joueur, pos_cible;
    int vie = INF;
    Personnage * tmp;    
    
    for(int i=0; i < etat->getPersoSize(); i++){
        Personnage& p = etat->getRefPersonnage(i);
        if (id != i) {
            if (p.getVie() <= vie) {
                vie = p.getVie();
                tmp = &p;
            }
        }
    }

    return tmp;
}

std::vector<int> IAheuristic::posCible(state::Etat* etat, int id, state::Personnage* ennemi){
    sf::Vector2f pos_cible, pos_ennemi, pos_joueur;
    int pm = 8;
    std::cout << "[Warning] : IAheuristic::posCible -> PM non implementes" << std::endl;

    pos_ennemi.x = ennemi->getX();
    pos_ennemi.y = ennemi->getY();
    
    pos_joueur.x = etat->getRefPersonnage(id).getX();
    pos_joueur.y = etat->getRefPersonnage(id).getY();
    
    
    while (pm != 0) {
        if(pos_joueur.x == pos_ennemi.x && pos_joueur.y != pos_ennemi.y){
            if(pos_joueur.y < pos_ennemi.y && pos_joueur.y != pos_ennemi.y-1){
                pos_joueur.y++;
                pm--;
            }
            else if(pos_joueur.y > pos_ennemi.y && pos_joueur.y != pos_ennemi.y+1){
                pos_joueur.y--;
                pm--;
            }
            else{
                break;
            }
        }
        else if(pos_joueur.y == pos_ennemi.y && pos_joueur.x != pos_ennemi.x){
            if(pos_joueur.x < pos_ennemi.x && pos_joueur.x != pos_ennemi.x-1){
                pos_joueur.x++;
                pm--;
            }
            else if(pos_joueur.x > pos_ennemi.x && pos_joueur.x != pos_ennemi.x+1){
                pos_joueur.x--;
                pm--;
            }
            else{
                break;
            }
        }
        else{
            if(pos_joueur.x < pos_ennemi.x && pos_joueur.x != pos_ennemi.x-1){
                pos_joueur.x++;
                pm--;
            }
            else if(pos_joueur.x > pos_ennemi.x && pos_joueur.x != pos_ennemi.x+1){
                pos_joueur.x--;
                pm--;
            }
        }
    }
    
    std::vector<int> cible;
    cible.push_back(pos_joueur.x);
    cible.push_back(pos_joueur.y);
    
    return cible;
    
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
    
    dist = abs(pos_joueur[1]-pos_ennemi[1])+abs(pos_joueur[0]-pos_ennemi[0]);
    
    if(dist == 1){
        ret = true;
    }
    else{
        ret = false;
    }
    
    return ret;
}