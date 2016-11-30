#include "../render.h"
#include "../state.h"
#include <iostream>

#define TRACE_RGRILLE 1

using namespace render;

void RenduGrille::dessin (sf::RenderTarget&  target, state::Etat* e){
	//testChgtMap(e);
	
	sf::RenderStates states;
	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}

RenduGrille::RenduGrille() {
	mut_lvl.lock();
	Parseur p;
	level = p.ParsingMap("res/Textures/carte/map1.txt");
	mut_lvl.unlock();
	charger ("res/Textures/carte/tileset.png", sf::Vector2u(48,48), 20, 16);
	mut_lvl.lock();
	level.push_back(1);
	mut_lvl.unlock();
}

RenduGrille::~RenduGrille(){

}

void RenduGrille::testChgtMap(state::Etat * e) {

	if (true) {
		Parseur p;
		switch(e->getMapActuel()) {
			case 1:
				mut_lvl.lock();
				level = p.ParsingMap("res/Textures/carte/map1.txt");
				mut_lvl.unlock();                        
				charger ("res/Textures/carte/tileset.png", sf::Vector2u(48,48), 20, 16);

				mut_lvl.lock();
				level.push_back(1);
				mut_lvl.unlock();
			break;
			case 2:
                mut_lvl.lock();             
				level = p.ParsingMap("res/Textures/carte/map2.txt");   
                mut_lvl.unlock();             
				charger ("res/Textures/carte/tileset.png", sf::Vector2u(48,48), 20, 16);
                mut_lvl.lock();
				level.push_back(2);
                mut_lvl.unlock();
				break;
			case 3:
                mut_lvl.lock();
				level = p.ParsingMap("res/Textures/carte/map3.txt"); 
                mut_lvl.unlock();               
				charger ("res/Textures/carte/tileset.png", sf::Vector2u(48,48), 20, 16);
                mut_lvl.lock();
				level.push_back(3);
                mut_lvl.unlock();
				break;
						
			case 4:     
                mut_lvl.lock();           
				level = p.ParsingMap("res/Textures/carte/map4.txt");   
                mut_lvl.unlock();             
				charger ("res/Textures/carte/tileset.png", sf::Vector2u(48,48), 20, 16);
                mut_lvl.lock();
				level.push_back(4);
                mut_lvl.unlock();
				break;
		}
	}
}

bool RenduGrille::charger (const std::string& tileset, sf::Vector2u  tileSize, unsigned int  width, unsigned int  height){
	// load the tileset texture
		
		if (!m_tileset.loadFromFile(tileset))
			return false;

		if (width * height != level.size()) {
			std::cout << "RenduGrille.cpp : Nombre de tiles incompatible avec la taille de level. Tiles" << width * height << " ("<<width <<"*" << height <<") pour " << level.size() << std::endl;
			return false;
		}
		
		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
		m_vertices.resize(width * height * 4);

		// populate the vertex array, with one quad per tile
		for (unsigned int i = 0; i < width; ++i)
			for (unsigned int j = 0; j < height; ++j)
			{
				// get the current tile number
                mut_lvl.lock();
				int tileNumber = level[i + j * width];
                mut_lvl.unlock();

				// find its position in the tileset texture
				int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
				int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
				quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
				quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
				quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
			}

		return true;
}

void RenduGrille::changeTileset (char * fichier) {
	mut_lvl.lock();
	Parseur p;
	level = p.ParsingMap(fichier);
	mut_lvl.unlock();
}