// Generated by dia2code
#ifndef GRILLEELEMENTS__H
#define GRILLEELEMENTS__H

/// class GrilleElements - 
class GrilleElements : public ListeElements {
  // Attributes
protected:
  int longueur;
  int largeur;
  // Operations
public:
  GrilleElements (int nv);
  int getLongueur ();
  int getLargeur ();
  bool const isAcces (int i, int j);
  void setCase (Element* e, int i, int j);
  void charger (const char* nom_fichier);
  void setLongueur (int i);
  void setLargeur (int i);
  void ajoutCaseAcces (int i, int j);
};

#endif