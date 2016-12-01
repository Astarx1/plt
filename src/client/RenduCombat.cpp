#include <SFML/Graphics/Color.hpp>

#include "RenduCombat.h"
#include "../render.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "../state.h"

using namespace render;
using namespace state;
using namespace client;

void RenduCombat::dessin(sf::RenderWindow& w, Etat* e, int id){
    Heros& h= e->getRefHeros(id);
    int pm,pa,niv,vie,lo,la;
    std::vector<sf::Drawable*> tabShape;
    sf::Time t;
    sf::Font f;
    //sf::RenderStates RS;
    
    f.loadFromFile("./res/font/arial.ttf");
    pm=h.getPM();
    pa=h.getPA();
    vie=h.getVie();
    niv=h.getNiveau();
    t=h.getTimer();
    lo=800;
    la=1000;
    
    sf::RectangleShape rectfond(sf::Vector2f(1000,244));
    rectfond.setPosition(0,635);
    rectfond.setFillColor(sf::Color::Cyan);
    tabShape.push_back(&rectfond);
    
    sf::RectangleShape rectCAC(sf::Vector2f(140,50));
    rectCAC.setPosition(30,lo-162);
    rectCAC.setFillColor(sf::Color(100, 250, 50));
    tabShape.push_back(&rectCAC);
    
    sf::RectangleShape rectDist(sf::Vector2f(140,50));
    rectDist.setPosition(30,lo-105);
    rectDist.setFillColor(sf::Color(100, 250, 50));
    tabShape.push_back(&rectDist);
    
    sf::RectangleShape rectPM(sf::Vector2f(100,40));
    rectPM.setPosition(280,lo-162);
    rectPM.setFillColor(sf::Color::White);
    tabShape.push_back(&rectPM);
    
    sf::RectangleShape rectPA(sf::Vector2f(100,40));
    rectPA.setPosition(280,lo-85);
    rectPA.setFillColor(sf::Color::White);
    tabShape.push_back(&rectPA);
    
    sf::CircleShape cercVie(40);
    cercVie.setPosition(420,lo-122);
    cercVie.setFillColor(sf::Color(255,0,0));
    tabShape.push_back(&cercVie);
    
    sf::CircleShape triangl1(40,3);
    triangl1.setPosition(580,lo-102);
    triangl1.setFillColor(sf::Color(0,0,128));
    tabShape.push_back(&triangl1);
    
    sf::CircleShape triangl2(40,3);
    triangl2.setFillColor(sf::Color(0,0,128));
    triangl2.setRotation(180);
    triangl2.setPosition(660,lo-102);
    tabShape.push_back(&triangl2);
    

    sf::Text texteCAC;
    texteCAC.setFont(f);
    texteCAC.setString("CAC");
    texteCAC.setColor(sf::Color::Black); 
    texteCAC.setPosition(70,lo-152);
    tabShape.push_back(&texteCAC);
    
    sf::Text texteDist;
    texteDist.setFont(f);
    texteDist.setString("Distance");
    texteDist.setColor(sf::Color::Black); 
    texteDist.setPosition(40,lo-95);
    tabShape.push_back(&texteDist);
    
    sf::Text textePM;
    textePM.setFont(f);
    textePM.setString("PM:" + std::to_string(pm));
    textePM.setColor(sf::Color::Black); 
    textePM.setPosition(290,lo-162);
    tabShape.push_back(&textePM);
    
    sf::Text textePA;
    textePA.setFont(f);
    textePA.setString("PA:" + std::to_string(pa));
    textePA.setColor(sf::Color::Black); 
    textePA.setPosition(290,lo-85);
    tabShape.push_back(&textePA);
    
    sf::Text texteVie;
    texteVie.setFont(f);
    texteVie.setString(std::to_string(vie));
    texteVie.setColor(sf::Color::Red); 
    texteVie.setPosition(510,lo-120);
    tabShape.push_back(&texteVie);
    
    sf::Text texteTemp;
    texteTemp.setFont(f);
    texteTemp.setString(std::to_string(t.asSeconds()));
    texteTemp.setColor(sf::Color::Blue); 
    texteTemp.setPosition(650,lo-102);
    tabShape.push_back(&texteTemp);
    
     for(unsigned int i=0;i<tabShape.size();i++)
   {
      w.draw(*tabShape[i]);
   }
    
    w.display();
       
    
}

RenduCombat::RenduCombat() {

}

RenduCombat::~RenduCombat(){

}
