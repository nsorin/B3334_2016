/*************************************************************************
                            UnionObject  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <UnionObject> (fichier UnionObject) --------------
#if ! defined ( UNIONOBJECT_H )
#define UNIONOBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "ComplexObject.h"
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <UnionObject>
// Classe caractérisant un objet complexe issu de l'union d'objets simples
// ou complexes
//------------------------------------------------------------------------

class UnionObject : public ComplexObject
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains(Point & p) const;

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

//------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, const UnionObject & object);

//-------------------------------------------- Constructeurs - destructeur
    UnionObject (std::string name);

    virtual ~UnionObject ( );

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

//----------------------------------------- Types dépendants de <UnionObject>

#endif // UNIONOBJECT_H
