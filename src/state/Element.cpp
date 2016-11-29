#include "Element.h"
#include "../state.h"
#include <iostream>

using namespace state;

Element::Element () {
    //à voir si on laisse vide
}

Element::~Element () {
}

int Element::getX () {
	return this->x;
}

int Element::getY () {
	return this->y;
}

void Element::setX (int const x) {
	this->x=x;
}

void Element::setY (int const y) {
    this->y=y;
}

int Element::getElemID () {
	return this->elemID;
}

void Element::setElemID (int i) {
    this->elemID=i;
}

void Element::setEtat(Etat* netat){
     etat = netat;
}

void Element::notifyObserver(char typeChg, sf::Time time){
    
    if(typeChg == 'g')
	std::cout<<"[Warning] Etat::notifyObserver: Etat notifie chgt Grille à Rendu !"<<std::endl;
    else
	std::cout<<"[Warning] Etat::notifyObserver: Etat notifie chgt Perso à Rendu !"<<std::endl;
	
    for(int i =0; i < observers.size();i++){
	observers[i]->maj(etat,typeChg,time);
				
    }
}
