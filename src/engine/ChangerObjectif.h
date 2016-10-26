// Generated by dia2code
#ifndef ENGINE__CHANGEROBJECTIF__H
#define ENGINE__CHANGEROBJECTIF__H

#include "../state.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace state {
  class Etat;
};
namespace engine {
  class Action;
}

#include "Action.h"

namespace engine {

  /// class ChangerObjectif - 
  class ChangerObjectif : public engine::Action {
    // Operations
  public:
    void run (state::Etat* e, std::vector<int> params, sf::Time t);
  };

};

#endif