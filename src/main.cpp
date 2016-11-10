#include <iostream>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "./state.h"
#include "./render.h"
#include "./engine.h"

// Fin test SFML


using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;

int main(int argc,char* argv[]) 
{
    // create the window
	cout << "[Main] Initialisation de ma fenetre" << endl;   
	sf::RenderWindow window(sf::VideoMode(1000, 800), "grille");

	cout << "[Main] Creation de l'etat" << endl;
	Etat* e= new Etat; 
	cout << "[Main] Rajout des persos" << endl;
	e->rajouterPerso('h');
	cout << "[Main] Accès a un perso" << endl;
	Personnage& p = e->getRefPersonnage(0);
	cout << "[Main] Parametrisation du perso" << endl;
	p.setTypePersonnage(TypePersonnage(HEROS));
	p.setX(200);
	p.setY(350);
	p.setDirection(OUEST);
        p.setEnDeplacement(false);
	sf::Clock c;
	sf::RenderStates rs;
        ListeCommandes liste;
        std::vector<int> v;
	v.push_back(1);
	// On devrait rajouter dans les commandes une vérification de l'existence des parametres.
	std::cout << "[Main] Initialisation de la Map" << std::endl;
	liste.Ajouter(Commande (e,"cm",c.getElapsedTime(),v,0));
	liste.ToutExecuter();
    // create the tilemap from the level definition
    //RenduGrille map;
	std::cout << "[Main] Initialisation du rendu" << endl;
	Rendu r;

    // run the main loop
    while (window.isOpen())
    {
        // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
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
                    Commande cmd(e,"d",c.getElapsedTime(),v,0);
                    liste.Ajouter(cmd);
			v.clear();
                    std::cout<< "pos Souris " << x << " et " << y << std::endl;
                    std::cout<< "pos Grille " << pos.x << " et " << pos.y << std::endl;
                    
                    //cmd.run();
                }
            }
        }

        // draw the map
        window.clear();
        Commande cmdUpdate(e,"u",c.getElapsedTime(),v,0);
        liste.Ajouter(cmdUpdate);
	liste.ToutExecuter();
	v.clear();
        r.run(e, window, c.getElapsedTime(), rs);
        window.display();
    }

    return 0;
}
