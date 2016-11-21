#include <iostream>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "./state.h"
#include "./render.h"
#include "./engine.h"
#include "./ia.h"
#include <vector>

// Fin test SFML


using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ia;

int main(int argc,char* argv[]) 
{
    // create the window
	cout << "[Main] Initialisation de ma fenetre" << endl;   
	sf::RenderWindow window(sf::VideoMode(1000, 800), "grille");

	cout << "[Main] Creation de l'etat" << endl;
	Etat* e = new Etat; 
	e->setEnCombat(false);

	cout << "[Main] Rajout des persos" << endl;
	for (int i = 0; i < 4; ++i) {
		e->rajouterPerso('h');
		Personnage& p = e->getRefPersonnage(i);
		p.setTypePersonnage(TypePersonnage(HEROS));
		sf::Vector2f pos = e->getGrilleCoord(10,10+i);
		p.setX(pos.x);
		p.setY(pos.y);
		p.setVie(100);
		cout << "[Main] Parametrisation du perso (" << p.getVie() << " PV)" << endl;
		p.setDirection(OUEST);
		p.setEnDeplacement(false);
	}

	sf::Clock c;
	sf::RenderStates rs;
 	ListeCommandes liste;
	std::vector<int> v;

	// On devrait rajouter dans les commandes une vérification de l'existence des parametres.
	std::cout << "[Main] Initialisation de la Map" << std::endl;
	v.push_back(1);
	liste.Ajouter(Commande (e,"im",c.getElapsedTime(),v,0));
	liste.ToutExecuter();
	v.clear();

	std::cout << "[Main] Initialisation du rendu" << std::endl;
	Rendu r;


	std::cout << "[Main] Initialisation de l'IA" << std::endl;
	IAminimale ias(e);

	std::cout << "[Main] Application de l'IA aux monstres" << std::endl;
	std::vector <int> IdPersosMonstres;
	for (int i = 1; i < e->getPersoSize(); ++i) {
			IdPersosMonstres.push_back(i);
	}
	std::cout << "[Main] Monstres : " << IdPersosMonstres.size() << std::endl;

    // run the main loop
	std::cout << "[Main] Debut de la boucle" << std::endl;
	std::cout << "/!\\ Si jamais, il n'y a qu'un seul personnage sur la carte, relancer le jeu"  << std::endl;

    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int x=event.mouseButton.x;
                    int y=event.mouseButton.y;
                    sf::Vector2f pos = e->getGrilleCoord(x,y); 
                    v.push_back(pos.x);
                    v.push_back(pos.y);

                    TypeID typeTmp = e->getStatutGrille(pos.x, pos.y);
                    /*if (true) {
  						if (typeTmp == TypeID(ACCES)) {
  							std::cout << "[" << pos.x << ", " << pos.y << "] : Acces" << std::endl;
  						}
		  				else if (typeTmp == TypeID(MONSTRE)){
		  					std::cout << "[" << pos.x << ", " << pos.y << "] : Monstre" << std::endl;
		  				}
		  				else if (typeTmp == TypeID(VIDE)) {
		  					std::cout << "[" << pos.x << ", " << pos.y << "] : Vide" << std::endl;
		  				}
		  				else if (typeTmp == TypeID(PERSO)) {
		  					std::cout << "[" << pos.x << ", " << pos.y << "] : Heros" << std::endl;
		  				}
                    }*/
                    switch (typeTmp) {
  						case TypeID(ACCES):
  							std::cout << "[" << pos.x << ", " << pos.y << "] : Acces" << std::endl;
  						break;
		  				case TypeID(MONSTRE):
		  					std::cout << "[" << pos.x << ", " << pos.y << "] : Monstre" << std::endl;
		  				break;
		  				case TypeID(VIDE):
		  					std::cout << "[" << pos.x << ", " << pos.y << "] : Vide" << std::endl;
		  				break;
		  				case TypeID(PERSO):
                    		if (!e->getEnCombat()) {
                    			std::cout << "[Main] Rentrée en combat ..." << std::endl;
                    			v.clear();
                    			Commande cmdEC(e,"ec",c.getElapsedTime(),v,0);
								liste.Ajouter(cmdEC);
                    			v.clear();
                    		}			
                    		else {
                    			std::cout << "[Main] On est déjà en combat ..." << std::endl; 
                    		}
                    	break;
                    }

                    v.clear();

                    std::cout << "[Main] pos Souris " << x << " et " << y << std::endl;
                    std::cout << "[Main] pos Grille " << pos.x << " et " << pos.y << std::endl;
                    
                    //cmd1.run();
                }
            }
        }

		// IA 
		for (int i = 0; i < IdPersosMonstres.size(); ++i) {
			liste.Ajouter(ias.exec_cmd(IdPersosMonstres[i], c.getElapsedTime())); 	
		}

		// Update Persos
		for (int i = 0; i < e->getPersoSize(); ++i) {
			Commande cmdUpdate(e,"u",c.getElapsedTime(),v,i);
			liste.Ajouter(cmdUpdate);
		}

        v.clear();
        int mapact;
        if (e->getMapActuel()==1)
        	mapact=2;
        else
        mapact=1;
        v.push_back(mapact);
        //std::cout<<"[main] changer de map:"<<v[0]<<std::endl;
		//Commande cmd1(e,"cm",c.getElapsedTime(),v,0);
		//liste.Ajouter(cmd1);
		v.clear();
		liste.ToutExecuter();

        // draw the map
        window.clear();
		v.clear();
		r.run(e, window, c.getElapsedTime(), rs);

  		/*GrilleElements& ge = e->getGrille();
  		
  		for (int i = 0; i < ge.getLargeur(); i++) {
  			for (int j = 0 ; j < ge.getLongueur(); ++j) {
  				TypeID t = e->getStatutGrille(i,j);

  				if (t == TypeID(ACCES))
  					std::cout << "[" << i << ", " << j << "] : Acces" << std::endl;
  				else if (t == TypeID(MONSTRE))
  					std::cout << "[" << i << ", " << j << "] : Monstre" << std::endl;
  				else if (t == TypeID(VIDE))
  					std::cout << "[" << i << ", " << j << "] : Vide" << std::endl;
  				else if (t == TypeID(PERSO))
  					std::cout << "[" << i << ", " << j << "] : Heros" << std::endl;
  			}
  		}
		while (1);*/
        window.display();
    }

    return 0;
}
