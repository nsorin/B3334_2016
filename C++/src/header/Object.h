/*************************************************************************
                            Object  -  description
                              -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Object> (fichier Object) --------------
#if ! defined ( OBJECT_H )
#define OBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <vector>
#include "Point.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Object>
// Classe abstraite caractérisant un objet du modèle
//
//------------------------------------------------------------------------

class Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Contains(Point & p) const;

    virtual void Move( int dx, int dy );

    std::string GetName( ) const;

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

    //------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, Object & object);

    //-------------------------------------------- Constructeurs - destructeur
    Object ( const Object & unObject );

    Object ( std::string n = "undefined" );

    virtual ~Object ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    std::string name; //nom de l'objet

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Object>
typedef std::map<std::string, Object*>::iterator it_model;
typedef std::vector<Object>::const_iterator it_objvect;

#endif // OBJECT_H
