#include <iostream>
#include <vector>
#include <thread>

//test Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "./state.h"
#include "./render.h"
#include "./engine.h"
#include "./ia.h"


// Fin test SFML


using namespace std;
using namespace sf;
using namespace state;
using namespace render;
using namespace engine;
using namespace ia;

int main(int argc,char* argv[]) {
	// create the window
	cout << "[Main] Initialisation de ma fenetre" << endl;   
	sf::RenderWindow window(sf::VideoMode(1000, 800), "grille");

	cout << "[Main] Creation de l'etat" << endl;
	Etat* e = new Etat; 
	e->setEnCombat(false);

	std::cout << "[Main] Initialisation du rendu" << std::endl;
	Rendu r;
	e->registerObserver(&r);

	cout << "[Main] Rajout des persos" << endl;
	for (int i = 0; i < 4; ++i) {
		e->rajouterPerso('h');
		Personnage& p = e->getRefPersonnage(i);
		p.setTypePersonnage(TypePersonnage(HEROS));
		sf::Vector2f pos = e->getGrilleCoord(10,10+i);
		p.setX(pos.x);
		p.setY(pos.y);
		p.setVie(100);
		p.setDirection(OUEST);
		p.setEnDeplacement(false);
	}

	std::cout << "[Main] Lancement de l'interface de commande" << std::endl;
	sf::Clock c;
	sf::RenderStates rs;
	ListeCommandes liste;
	thread th_engine (&ListeCommandes::ToutExecuter, &liste);
	std::vector<int> v;

	// On devrait rajouter dans les commandes une vérification de l'existence des parametres.
	std::cout << "[Main] Initialisation de la Map" << std::endl;
	v.push_back(1);
	liste.Ajouter(Commande (e,"im",c.getElapsedTime(),v,0));
	v.clear();

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
	std::cout << "/!\\ Pour changer de map, cliquer juste au dessus de la lanterne"  << std::endl;

	int s = 0;
	int tour_actuel = -1;
	while (window.isOpen()) {
		// handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if(event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					int x=event.mouseButton.x;
					int y=event.mouseButton.y;
					sf::Vector2f pos = e->getGrilleCoord(x,y); 
					v.clear();
					v.push_back(pos.x);
					v.push_back(pos.y);

					Commande cmd(e,"d",c.getElapsedTime(),v,0);
					liste.Ajouter(cmd);	
					v.clear();

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
					Commande cmdCM(e,"cm",c.getElapsedTime(),v,0);
					Commande cmdEC(e,"ec",c.getElapsedTime(),v,0);
					std::cout << "[Main] Clic Souris (" << x << " - " << pos.x << ", " << y << " - " << pos.y << ")" << std::endl;

					switch (typeTmp) {
						case ACCES:
							std::cout << "[Main] [" << pos.x << ", " << pos.y << "] : Acces" << std::endl;
							v.clear();
							liste.Ajouter(cmdCM);
							v.clear();
						break;

						case MONSTRE :
							std::cout << "[Main] [" << pos.x << ", " << pos.y << "] : Monstre" << std::endl;
							if (e->getEnCombat()) {
								std::cout << "[Main] Ajout de la commande d'attaque" << std::endl;
								
								liste.Ajouter(cmdEC);
								v.clear();								
							}
						break;

						case VIDE :
						break;

						case PERSO :
							if (!e->getEnCombat()) {
								std::cout << "[Main] Rentrée en combat ..." << std::endl;
								v.clear();
								liste.Ajouter(cmdEC);
								v.clear();
							}
							else {
							std::cout << "[Main] On est déjà en combat ..." << std::endl; 
							}
						break;
					}

					v.clear();


					//cmd1.run();
				}
			}
		}

		IdPersosMonstres.clear();
		for (int i = 0; i < e->getPersoSize(); ++i) {
			IdPersosMonstres.push_back(i);
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

		// draw the map
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

		if (e->getEnCombat ()) {
			Combat& c = e->getRefCombat ();
			if (tour_actuel != c.getTour ()) {
				tour_actuel =  c.getTour ();
				std::cout << "[Main] En combat, tour : " << tour_actuel << std::endl;
			}
		}
		window.display();
	}
	return 0;
}
