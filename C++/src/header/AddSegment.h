/*************************************************************************
                            AddSegment  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <AddSegment> (fichier AddSegment) --------------
#if ! defined ( ADDSEGMENT_H )
#define ADDSEGMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "Segment.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <AddSegment>
//
//
//------------------------------------------------------------------------

class AddSegment : public Command
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
    AddSegment ( std::string & data, bool ignoreExtraValues = false );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~AddSegment ( );
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
    Segment *object;
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <AddSegment>

#endif // ADDSEGMENT_H
