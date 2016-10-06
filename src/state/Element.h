// Generated by dia2code
#ifndef ELEMENT__H
#define ELEMENT__H

/// class Element - 
class Element : public IAccepteVisite {
  // Associations
  // Attributes
protected:
  int x;
  int y;
  TypeID typeID;
  int elemID;
  // Operations
public:
  Element ();
  ~Element ();
  virtual TypeID getTypeID () = 0;
  virtual void accepte (IVisiteur& v ) = 0;
  int getX ();
  int getY ();
  void setX (int const x);
  void setY (int const y);
  int getElemID ();
  void setElemID (int i);
};

#endif