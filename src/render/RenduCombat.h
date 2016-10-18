// Generated by dia2code
#ifndef RENDER__RENDUCOMBAT__H
#define RENDER__RENDUCOMBAT__H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../state.h"

namespace render {
  class RenduType;
  class RectTexte;
  class CerTexte;
};
namespace state {
  class Etat;
}

#include "RenduType.h"
#include "RectTexte.h"
#include "CerTexte.h"

namespace render {

  /// class RenduCombat - 
  class RenduCombat {
    // Associations
    // Attributes
  public:
    RenduType IconeAttaqueDist;
    RenduType IconeAttaqueCAC;
    RectTexte IconePA;
    RectTexte IconePM;
    CerTexte IconeVie;
    sf::CircleShape IconeTemps;
    sf::CircleShape IconeTourSuiv;
    // Operations
  public:
    void dessin (sf::RenderWindow& w, state::Etat* e, int id);
    RenduCombat ();
    ~RenduCombat ();
  };

};

#endif