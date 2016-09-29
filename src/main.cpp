#include <iostream>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include "state.hpp"

using namespace std;
using namespace sf;

int main(int argc,char* argv[]) 
{

    RenderWindow app(VideoMode(1200,800),"Menu Démarrer");
    
   /* Texture texture;
        if (!texture.loadFromFile("fond_ecran.jpg"))
            return EXIT_FAILURE;
    Sprite sprite(texture);
    */
    while(app.isOpen()){
    
        Event event;
        
        while(app.waitEvent(event)){
        
            if(event.type == Event::Closed)
                app.close();
        }
        
        app.clear();
        
        //app.draw(sprite);
        
        app.display();
    }
    
    cout << "It works !" << endl;
<<<<<<< HEAD
  
=======
    cout << "cc" << endl;
    cout << "tout va bien" << endl;
>>>>>>> 39d4ef848f9c248dc22d2391ee373e00637185c0
    return 0;
}
