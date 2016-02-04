
/*************************************************************************
                            Union  -  description
                             -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//---------- Réalisation de la classe <Union> (fichier Union) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../header/Union.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Union::Do( map<string, Object*> & model )
// Algorithme :
//
{
    undone = false;
    if ( model.find(objectName) == model.end() )
    {
        for(unsigned int i=0; i<components.size()-1; i++)
        {
            if ( model.find(components[i]) != model.end() )
            {
                object->AddObject(model[components[i]]);
            }
            else
            {
                delete object;
                return false;
            }
        }
        model[objectName] = object;
        return true;
    }
    else
    {
        delete object;
        return false;
    }
} //----- Fin de Do

bool Union::Undo ( map<string, Object*> & model )
// Algorithme :
//
{
    undone = true;
    object->ClearObjects();
    model.erase(objectName);
    return true;
} //----- Fin de Undo


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Union::Union ( string & data )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Union>" << endl;
#endif
    undone = false;
    istringstream iss(data);
    iss >> objectName;

    do
    {
        string n;
        iss >> n;
        components.push_back(n);
    } while (iss);
    object = new UnionObject(objectName);
} //----- Fin de Union


Union::~Union ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Union>" << endl;
#endif
    if(undone)
    {
        delete object;
    }
} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
