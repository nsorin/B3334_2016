/*************************************************************************
                            Load  -  description
                             -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Load> (fichier Load) --------------
#if ! defined ( LOAD_H )
#define LOAD_H

//--------------------------------------------------- Interfaces utilisées
#include "Command.h"
#include "AddSegment.h"
#include "AddPolygone.h"
#include "AddRectangle.h"
#include "Union.h"
#include "Intersection.h"
#include <fstream>

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Load>
// Commande de chargement d'un modèle à partir d'un fichier texte
//
//------------------------------------------------------------------------

class Load : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Load ( std::string & data );

    virtual ~Load ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées
    //méthode d'analyse d'une ligne de fichier
    bool parseLine(std::string & line);

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    std::string fileName; //nom du fichier
    std::map<std::string, Object*> mapObjects; //modèle chargé
    std::map<std::string, Object*> oldObjects; //ancien modèle

    std::vector<ComplexObject*> ops;
    std::vector<std::map<std::string, Object*> > tempObjects;
    unsigned int opIndex;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Load>

#endif // LOAD_H
