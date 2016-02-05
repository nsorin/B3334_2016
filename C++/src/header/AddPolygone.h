/*************************************************************************
                            AddPolygone  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <AddPolygone> (fichier AddPolygone) --------------
#if ! defined ( ADDPOLYGONE_H )
#define ADDPOLYGONE_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "Polygone.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AddPolygone>
// Commande d'ajout d'un polygone convexe au modèle
//
//------------------------------------------------------------------------

class AddPolygone : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    AddPolygone ( std::string & data );

    virtual ~AddPolygone ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Polygone *object; //Polygone ajouté
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <AddPolygone>

#endif // ADDPOLYGONE_H
