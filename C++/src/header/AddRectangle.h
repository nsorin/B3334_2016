/*************************************************************************
                            AddRectangle  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <AddRectangle> (fichier AddRectangle) --------------
#if ! defined ( ADDRECTANGLE_H )
#define ADDRECTANGLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AddRectangle>
// Commande d'ajout d'un rectangle au modèle
//
//------------------------------------------------------------------------

class AddRectangle : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    AddRectangle ( std::string & data, bool ignoreExtraValues = false );

    virtual ~AddRectangle ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Rectangle *object; //Rectangle ajouté
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <AddRectangle>

#endif // ADDRECTANGLE_H
