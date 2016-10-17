#include "RenduPerso.h"

/* Temps en milliseconde durant lequel un sprite sera affiche */
#define TEMPS_SPRITE 500
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

void RenduPerso::dessin (sf::RenderWindow& w, state::Etat* e, int id, sf::Clock& cl){
	Personnage& p = (e->getRefPersonnage(id));
	int tmpDeplacement = p.getTimer();
	bool enDeplacement = p.getEnDeplacement();
	Direction dir = p.getDirection();
	sf::Time t = cl.getElapsedTime();
	TypePersonnage tp = p.getTypePersonnage();

	int spr = 0;
	if (dir == SUD)
		spr += NB_SPRITE+1;
	else if (dir == EST)
		spr += (NB_SPRITE+1)*2;
	else if (dir == OUEST)
		spr += (NB_SPRITE+1)*3;

	if (enDeplacement)
		spr++;

	spr += valeurEntiere((t.asMilliseconds() % (NB_SPRITE * TEMPS_SPRITE)) / TEMPS_SPRITE);

	switch (tp) {
		case HEROS:
		w.draw(Heros1.sprites[spr]);
		break;

		case HEROINE:
		w.draw(Heros2.sprites[spr]);
		break;

		case MONSTRE1:
		w.draw(Monstre1.sprites[spr]);
		break;

		case MONSTRE2:
		w.draw(Monstre2.sprites[spr]);
		break;

		case MONSTRE3:
		w.draw(Monstre3.sprites[spr]);
		break;

		case MONSTRE4:
		w.draw(Monstre4.sprites[spr]);
		break;

		case BOSS:
		w.draw(Monstre5.sprites[spr]);
		break;
	}
}

RenduPerso::RenduPerso () {
}

RenduPerso::~RenduPerso () {
}
