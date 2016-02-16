/*************************************************************************
                            Move  -  description
                             -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Move> (fichier Move) --------------
#if ! defined ( MOVE_H )
#define MOVE_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Move>
// Commande permettant de mouvoir un objet du modèle
//
//------------------------------------------------------------------------

class Move : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Move ( std::string & data );

    virtual ~Move ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    std::string objectName; //nom de l'objet ciblé
    int dx; //incrément d'abscisses
    int dy; //incrément d'ordonnées

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Move>

#endif // MOVE_H
