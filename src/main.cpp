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
    sf::RenderWindow window(sf::VideoMode(800, 600), "grille");
    Etat* e= new Etat;
    // define the level with an array of tile indices
   

    // create the tilemap from the level definition
    RenduGrille map;

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
        map.dessin(window,e);
        window.display();
    }

    return 0;
}
