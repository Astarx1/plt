#include "../engine.h"
#include <ctime>


using namespace state;
using namespace sf;


namespace engine {

/* Cette fonction permet de vérifier si le joueur peut se déplacer à la nouvelle
 * position (newX,newY)
 * 
 * À compléter!!!
 */   
bool Regles::peutDeplacer(state::Etat* e, int id, int newX, int newY){
    Personnage& perso = e->getRefPersonnage(id);
    if(e->getEnCombat()){
        // Si le personnage est en combat
        if(perso.getPM() == 0){
            return false;
        }
        else if(!(e->getPerso()).isPerso(newX,newY)){
            return false;
            // Penser au cas en réseau où il peut y avoir d'autre héros
        }
    }
    else{
        // Si le personnage n'est pas en combat
        if(newY < 1000 && newX < 1000 ){
            // Seuil à ajuster!
            return false;
        }
    }
    return true;
}

/* Cette fonction permet de vérifier si un personnage de type Heros peut entrer
 * en combat. 
 */
bool Regles::peutEntrerCombat (state::Etat* e, int id){
    Personnage& perso = e->getRefPersonnage(id);
    if(perso.isJoueur()){
        if(e->getEnCombat() == false){
            return true;
        }
    }
    else{
        return false;
    }
}

/*Cette fonction permet de vérifier si le joueur se trouve sur une case ACCES
 *afin de pourvoir changer de carte
 */
bool Regles::peutChangerMap (state::Etat* e, int id){    
    Personnage& perso = e->getRefPersonnage(id);
    if((e->getGrille().isAcces(perso.getX(),perso.getY()))){
        return true;
    }
   
    return false;
}

/* Cette fonction permet de vérifier s'il est possible de quitter le mode combat.
 */
bool Regles::peutQuitterCombat(state::Etat* e){
    bool retH = false;
    bool retM = false;
    ListeElements persos = e->getPerso();
    
    for(size_t i=0; persos.size(); i++){
        if(e->getRefPersonnage(i).getTypeID() == HEROS && e->getRefPersonnage(i).getVie() >0){
            retH = true;
        }
        if(e->getRefPersonnage(i).getTypeID() == MONSTRE && e->getRefPersonnage(i).getVie() >0){
            retM = true;
        }
    }
    return !(retH && retM);
        
}

bool Regles::peutAttaquer(state::Etat* e, int id){
    Personnage& perso = e->getRefPersonnage(id);
    
    if(e->getEnCombat()){
        if(perso.getPA() > 0){
            return true;
        }
    }
    else{
        return false;
    }
}

bool Regles::doitPasserTour(state::Etat* e, int id, sf::Time t){
    Combat& combat = e->getRefCombat();
    Time timeDeb = combat.getTimerDebutTour();
    if((t.asSeconds()- timeDeb.asSeconds()) >= 60){
        return true;
    }
    return false;
}

bool Regles::peutAccederMenu(state::Etat* e){
    if(e->getEnCombat()){
        return false;
    }
    else{
        return false;
    }
}

bool Regles::peutAccederInfoPerso(state::Etat* e){
    if(e->getEnCombat()){
        return false;
    }
    else{
        return false;
    }
}

bool Regles::peutAugmenterNiv(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    int exp = e->getRefHeros(id).getExp();
    
    if(exp >= nv*100){
        return true;
    }
    
    return false;
  
}

int Regles::augmenterPM(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    
    switch(nv){
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
    }
}

int Regles::augmenterPA(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    
    switch(nv){
        case 1:
            return 6;
        case 2:
            return 7;
        case 3:
            return 8;
        case 4:
            return 9;
        case 5:
            return 10;
        case 6:
            return 11;
        case 7:
            return 12;
        case 8:
            return 13;
        case 9:
            return 14;
        case 10:
            return 15;
    }
}

int Regles::augmenterPV(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    
    switch(nv){
        case 1:
            return 150;
        case 2:
            return 200;
        case 3:
            return 250;
        case 4:
            return 300;
        case 5:
            return 350;
        case 6:
            return 400;
        case 7:
            return 450;
        case 8:
            return 500;
        case 9:
            return 550;
        case 10:
            return 600;
    }
}

int Regles::augmenterForce(state::Etat* e, int id){
    int nv = e->getRefPersonnage(id).getNiveau();
    
    switch(nv){
        case 1:
            return 3;
        case 2:
            return 4;
        case 3:
            return 5;
        case 4:
            return 6;
        case 5:
            return 7;
        case 6:
            return 8;
        case 7:
            return 9;
        case 8:
            return 10;
        case 9:
            return 11;
        case 10:
            return 12;
    }
}

/* Cette fonction permet de définir les monstres associés à la carte
 * 
 * À prévoir la génération des positions aléatoires pour l'instanciation des monstres.
 */
std::vector<state::Personnage*> Regles::defMonstreCarte(state::Etat* e){
    srand(time(NULL));
    std::vector<state::Personnage*> list;
    int map_actuel = e->getMapActuel();
    int alea_monstre = rand()%5 + 1;
        
    switch(map_actuel){
        case 1: 
            for(size_t i=0; i<alea_monstre; i++){
                int alea_nv = rand()%4 + 1;
                if(rand()%2 == 0){
                    Monstre p(1,1,alea_nv,MONSTRE1);
                    list.push_back(&p);
                }
                else{
                    Monstre p(1,1,alea_nv,MONSTRE2);
                    list.push_back(&p);
                }
            }
            return list;
            
        case 2:
            for(size_t i=0; i<alea_monstre; i++){
                int alea_nv = rand()%6 + 4;
                if(rand()%2 == 0){
                    Monstre p(1,1,alea_nv,MONSTRE3);
                    list.push_back(&p);
                }
                else{
                    Monstre p(1,1,alea_nv,MONSTRE4);
                    list.push_back(&p);
                }
            }
            return list;
            
        case 3:
            Monstre p(1,1,10,BOSS);
            list.push_back(&p);
            return list;
    }
    
}

int Regles::defCarteSuiv (state::Etat* e, int id){
    int map_actuel = e->getMapActuel();
    bool combat = e->getEnCombat();
    int mapSuiv = 0;
    int x = e->getRefHeros(id).getX();
    int y = e->getRefHeros(id).getY();
    
    switch(map_actuel){
        case 1: 
            if(combat)
                mapSuiv = 2;
            else if(e->getGrille().isAcces(x,y))
                mapSuiv = 3;
            return mapSuiv;
        case 2:
            if(!combat)
                mapSuiv = 1;
            return mapSuiv;
        case 3:
            if(combat)
                mapSuiv = 4;
            else if(e->getGrille().isAcces(x,y) && x < 5)
                mapSuiv = 1;
            else mapSuiv = 5;
            return mapSuiv;
        case 4:
            if(!combat)
                mapSuiv = 3;
            return mapSuiv;
        case 5:
            if(combat)
                mapSuiv = 6;
            else if(e->getGrille().isAcces(x,y))
                mapSuiv = 3;
            return mapSuiv;
            
    }
}

};
