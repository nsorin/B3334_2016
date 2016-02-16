
/*************************************************************************
                            Intersection  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//---------- Réalisation de la classe <Intersection> (fichier Intersection) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "../header/Intersection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
bool Intersection::Do ( map<string, Object*> & model )
{
    undone = false;
    if ( model.find(objectName) == model.end() && !invalid )
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

bool Intersection::Undo ( map<string, Object*> & model )
{
    undone = true;
    object->ClearObjects();
    model.erase(object->GetName());
    return true;
} //----- Fin de Undo


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( string & data )
{
#ifdef MAP
    cout << "Appel au constructeur de <Intersection>" << endl;
#endif
    undone = false;
    invalid = false;
    istringstream iss(data);
    iss >> objectName;

    do
    {
        string n;
        iss >> n;
        components.push_back(n);
    } while (iss);
    invalid = components.size() < 2;
    object = new InterObject(objectName);
} //----- Fin de Intersection


Intersection::~Intersection ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Intersection>" << endl;
#endif
    if(undone)
    {
        delete object;
    }
} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
