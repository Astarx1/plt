// Generated by dia2code
#ifndef RENDER__PARSEUR__H
#define RENDER__PARSEUR__H

#include <vector>
#include <string>

namespace render {

  /// class Parseur - 
  class Parseur {
    // Operations
  public:
    std::vector<int> ParsingMap (char* fichier);
    std::vector<std::vector<std::vector<std::vector<int> > > > ParsingTextures (char * fichier);
    std::string trim (std::string & s);
    std::string ftos (char* fichier);
    std::vector<std::string> ParsingString  (std::string s, char marqueur);
  };

};

#endif
