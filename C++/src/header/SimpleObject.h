/*************************************************************************
                            SimpleObject  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <SimpleObject> (fichier SimpleObject) --------------
#if ! defined ( SIMPLEOBJECT_H )
#define SIMPLEOBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "Object.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <SimpleObject>
// Classe caractérisant un objet simple
//
//------------------------------------------------------------------------

class SimpleObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains(Point & p) const;

    Point * GetTabPoints( ) const;

    unsigned int GetSize() const;

    void Move(int dx, int dy);

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

//------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, const SimpleObject & object);

//-------------------------------------------- Constructeurs - destructeur
    SimpleObject ( std::string n = "", unsigned int np = 2 );

    virtual ~SimpleObject ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    Point * tabPoints; //tableau de points caractérisant l'objet
    unsigned int nPoints; //nombre de points

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SimpleObject>

#endif // SIMPLEOBJECT_HŜ
