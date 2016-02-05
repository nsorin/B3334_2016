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
//
//
//------------------------------------------------------------------------

class AddRectangle : public Command
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
    AddRectangle ( std::string & data, bool ignoreExtraValues = false );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddRectangle ( );
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
    Rectangle *object;
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <AddRectangle>

#endif // ADDRECTANGLE_H
