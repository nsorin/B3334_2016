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
// Commande de création d'objet complexe issu de l'union d'objets simples
// ou complexes
//------------------------------------------------------------------------

class Union : public Command
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    virtual bool Do ( std::map<std::string, Object*> & model );

    virtual bool Undo ( std::map<std::string, Object*> & model );

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Union ( std::string & data );

    virtual ~Union ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    UnionObject *object; //Objet créé
    std::vector<std::string> components; //vector des noms des composants
    std::string objectName; //nom de l'objet
    bool invalid;

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Union>

#endif // UNION_H
