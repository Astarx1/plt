#include "RectTexte.h"
#include "../render.h"

using namespace render;
using namespace client;

void RectTexte::ChangeText(const sf::String& txt){
    texte.setString(txt);
}

RectTexte::RectTexte(){

}

RectTexte::~RectTexte(){

}

