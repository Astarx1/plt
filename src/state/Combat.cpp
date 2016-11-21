#include "Combat.h"

using namespace state;

Combat::Combat () {
}

Combat::~Combat () {
}

void Combat::createListe (ListeElements listePersonnages) {
	for(int i = 0; i < listePersonnages.size(); i++)
		listeTour.push_back(i);
	tourActuel = -1;
}

void Combat::tourSuivant (sf::Time t) {
	if (tourActuel >= 0) {
		timerDebutTour = t;
		int i=0;

		while (listeTour[i] != tourActuel && i < 100)
			++i;
		if (i < listeTour.size() - 1)
			tourActuel = listeTour[(++i)];
		else 
			tourActuel = listeTour[0];
	}
	else {
		tourActuel = 0;
	}
}

sf::Time Combat::getTimerDebutTour () {
	return timerDebutTour;
}
