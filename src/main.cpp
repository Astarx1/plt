#include <iostream>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "./state.h"
#include "./render.h"

// Fin test SFML


using namespace std;
using namespace sf;
using namespace state;
using namespace render;

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
	p.setX(200);
	p.setY(350);
	p.setDirection(EST);

	sf::Clock c;
	sf::RenderStates rs;



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
        }

        // draw the map
        window.clear();
        r.run(e, window, c, rs);
        window.display();
    }

    return 0;
}
