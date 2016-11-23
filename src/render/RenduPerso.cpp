#include "RenduPerso.h"
#include "../render.h"
#include <iostream>

/* Temps en milliseconde durant lequel un sprite sera affiche */
#define TEMPS_SPRITE 400
/* Nombre de sprite dans une periode complete. Ne prend pas en compte le sprite a l'arret */
#define NB_SPRITE 2

using namespace render;
using namespace state;

int valeurEntiere (float a) {
	if (a >= 0) {
		int i = 0;
		while (i < a)
			i++;
		if (i == a) {
			return a;
		}
		else {
			return i-1;
		}
	}
	else {
		return 0;
	}
}

void RenduPerso::dessin (sf::RenderWindow& w, state::Etat* e, int id, sf::Time cl, sf::RenderStates rs){
	int nb_perso = (e->getPerso()).size();

	vertices.clear();
	vertices.resize(nb_perso * 4);
	vertices.setPrimitiveType(sf::Quads);

	std::vector<std::vector<std::vector<std::vector<int> > > > th1; 
	Parseur pp;
	
	for (int i = 0; i < nb_perso; ++i) {
                Personnage& p = (e->getRefPersonnage(i));
		int h_sprite = 0;
		int l_sprite = 0;
		int x_sprite = p.getX();
		int y_sprite = p.getY();

		sf::Vertex* quad = &vertices[i*4];
		int tmpDeplacement = p.getTimer().asMilliseconds();
		bool enDeplacement = p.getEnDeplacement();
		Direction dir = p.getDirection();
		TypePersonnage tp = p.getTypePersonnage();

		int spr_hauteur = 3;
		int spr_longueur = 0;

		if (dir == SUD)
			spr_hauteur = 0;
		else if (dir == EST)
			spr_hauteur = 1;
		else if (dir == OUEST)
			spr_hauteur = 2;

		if (p.getEnDeplacement()) 
			spr_longueur = valeurEntiere((cl.asMilliseconds() % (NB_SPRITE * TEMPS_SPRITE)) / TEMPS_SPRITE); 
    
		switch (tp) {
			case HEROS:
				th1 = pp.ParsingTextures ("res/Textures/heros/heros_1.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;

			case HEROINE:
				th1 = pp.ParsingTextures ("res/Textures/heros/heros_2.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;

			case MONSTRE1:
				th1 = pp.ParsingTextures ("res/Textures/monstres/monstre1.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 79;
						l_sprite = 73;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;

			case MONSTRE2:
				th1 = pp.ParsingTextures ("res/Textures/monstres/monstre2.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 38;
						l_sprite = 50;                                   
					}
			break;

			case MONSTRE3:
				th1 = pp.ParsingTextures ("res/Textures/heros/monstre3.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;

			case MONSTRE4:
				th1 = pp.ParsingTextures ("res/Textures/heros/monstre4.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;

			case BOSS:
				th1 = pp.ParsingTextures ("res/Textures/heros/boss.txt");
					if (th1.size()>0) {
						quad[3].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][0][0],th1[spr_hauteur][spr_longueur][0][1]);
						quad[2].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][1][0],th1[spr_hauteur][spr_longueur][1][1]);
						quad[0].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][2][0],th1[spr_hauteur][spr_longueur][2][1]);
						quad[1].texCoords = sf::Vector2f(th1[spr_hauteur][spr_longueur][3][0],th1[spr_hauteur][spr_longueur][3][1]);
						h_sprite = 47;
						l_sprite = 43;
					}
					else {
						quad[0].texCoords = sf::Vector2f(0,0);
						quad[1].texCoords = sf::Vector2f(0,0);
						quad[2].texCoords =  sf::Vector2f(0,0);
						quad[3].texCoords =  sf::Vector2f(0,0);
						h_sprite = 25;
						l_sprite = 25;                                   
					}
			break;
		}	  
              	
		quad[0].position = sf::Vector2f(x_sprite - l_sprite, y_sprite+h_sprite/2);
		quad[1].position = sf::Vector2f(x_sprite , y_sprite+h_sprite/2);
		quad[3].position = sf::Vector2f(x_sprite - l_sprite, y_sprite-h_sprite/2);
		quad[2].position = sf::Vector2f(x_sprite, y_sprite-h_sprite/2);             
	} 
	rs.texture = &tileset;
	w.draw(vertices,rs);
}

RenduPerso::RenduPerso () {
	tileset.loadFromFile("res/Textures/persos.png");
	vertices.setPrimitiveType(sf::Quads);
}

RenduPerso::~RenduPerso () {
}
