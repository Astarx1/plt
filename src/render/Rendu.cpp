#include "../render.h"

#include <mutex>
#include <iostream>

#define TRACE_RENDU 1
#define TRACE_RENDU_RUN 0
#define TRACE_RENDU_MAJ 1

using namespace render;
using namespace state;

void Rendu::run (Etat* e, sf::RenderWindow& sw, sf::Time cl, sf::RenderStates rs) {
	mut_cmdbuf.lock();
	cmd = cmd_buf;
	mut_cmdbuf.unlock();

	bool r_perso = false;
	bool r_grille = false;

	for (int i = cmd.size()-1; i >= 0; --i) {
		if (cmd[i].getTC() == 'p' && !r_perso) {
			#if TRACE_RENDU == 1 && TRACE_RENDU_RUN == 1
			std::cout << "Rendu::run : On met à jour les persos" << std::endl;
			#endif
			r_perso = true;
			rp.testChgtPerso(e, cmd[i].getTime()); 
		}
		else if (cmd[i].getTC() == 'g' && !r_grille) {
			r_grille = true;
			rg.testChgtMap(e); 
			r_perso = true;
			rp.testChgtPerso(e, cmd[i].getTime()); 
		}
	}
	sw.clear();
	rg.dessin (sw, e);
	rp.dessin(sw, e, 0, cl, rs);
}

Rendu::Rendu () {  
}

void Rendu::maj(state::Etat* e, char typechang, sf::Time t){
	std::lock_guard<std::mutex> lock(mut_cmdbuf);
	#if TRACE_RENDU==1 && TRACE_RENDU_MAJ==1
	if(typechang == 'g')
		std::cout << "Rendu::maj : Nouvelle commande RG" << std::endl;
	else
		std::cout << "Rendu::maj : Nouvelle commande RP" << std::endl;
	#endif
	cmd_buf.push_back(cmdRendu(e, typechang, t));
}