/*************************************************************************
                            Intersection  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Intersection> (fichier Intersection) --------------
#if ! defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "InterObject.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Intersection>
//
//
//------------------------------------------------------------------------

class Intersection : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual bool Undo ( std::map<std::string, Object*> & model );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Intersection ( std::string & data );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Intersection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    InterObject *object;
    std::vector<std::string> components;
    std::string objectName;
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Intersection>

#endif // INTERSECTION_H
