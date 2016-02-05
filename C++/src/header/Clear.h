/*************************************************************************
                            Clear  -  description
                             -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Clear> (fichier Clear) --------------
#if ! defined ( CLEAR_H )
#define CLEAR_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Clear>
// Commande de suppression du modèle actuel
//
//------------------------------------------------------------------------

class Clear : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Clear ( );

    virtual ~Clear ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    std::map<std::string, Object*> mapObject; //CModèle supprimé

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Clear>

#endif // CLEAR_H
