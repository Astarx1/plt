// Generated by dia2code
#ifndef STATE__OBSERVER__H
#define STATE__OBSERVER__H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace state {
  class Etat;
}

namespace state {

  /// class Observer - 
  class Observer {
    // Operations
  public:
    virtual ~Observer ();
    virtual void maj (state::Etat* e, char typechang, sf::Time t) = 0;
  };

};

#endif