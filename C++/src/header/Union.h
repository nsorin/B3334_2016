/*************************************************************************
                            Union  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Union> (fichier Union) --------------
#if ! defined ( UNION_H )
#define UNION_H

//--------------------------------------------------- Interfaces utilisées
#include "UnionObject.h"
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Union>
//
//
//------------------------------------------------------------------------

class Union : public Command
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
    Union ( std::string & data );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Union ( );
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
    UnionObject *object;
    std::vector<std::string> components;
    std::string objectName;
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Union>

#endif // UNION_H
