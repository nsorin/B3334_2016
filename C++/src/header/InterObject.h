/*************************************************************************
                            InterObject  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <InterObject> (fichier InterObject) --------------
#if ! defined ( INTEROBJECT_H )
#define INTEROBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "ComplexObject.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <InterObject>
// Classe caractérisant un objet issue de l'intersection d'objets simples
// ou complexes
//------------------------------------------------------------------------

class InterObject : public ComplexObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains(Point & p) const;

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

//------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, const InterObject & object);

//-------------------------------------------- Constructeurs - destructeur

    InterObject (std::string name);

    virtual ~InterObject ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <InterObject>

#endif // INTEROBJECT_H
