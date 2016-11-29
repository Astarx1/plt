#include "../render.h"

#include <mutex>
#include <iostream>

using namespace render;
using namespace state;

void Rendu::run (Etat* e, sf::RenderWindow& sw, sf::Time cl, sf::RenderStates rs) {
	rg.dessin(sw, e);
	rp.dessin(sw, e, 0, cl, rs);
}

Rendu::Rendu () {  
}

void Rendu::maj(state::Etat* e, char typechang, sf::Time t){
	std::lock_guard<std::mutex> lock(mut_cmdbuf);
	cmd_buf.push_back(cmdRendu(e, typechang, t));
}