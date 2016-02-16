/*************************************************************************
                            Delete  -  description
                              -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Delete> (fichier Delete) --------------
#if ! defined ( DELETE_H )
#define DELETE_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Delete>
// Commande de suppression d'objets du modèle
//
//------------------------------------------------------------------------

class Delete : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model);

    virtual bool Undo ( std::map<std::string, Object*> & model);

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Delete ( std::string & data );

    virtual ~Delete ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    std::map<std::string, Object*> mapObject;//modèle avant suppression
    std::vector<std::string> toDelete;//vector des noms d'objets supprimés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Delete>

#endif // DELETE_H
