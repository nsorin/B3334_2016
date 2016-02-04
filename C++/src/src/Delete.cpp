
    /*************************************************************************
                               Delete  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Delete> (fichier Delete) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Delete.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques

    bool Delete::Do ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        undone = false;
        for(unsigned int i=0; i<toDelete.size(); i++)
        {
            if(model.find(toDelete[i]) == model.end())
            {
                return false;
            }
        }

        for(unsigned int i=0; i<toDelete.size(); i++)
        {
            mapObject[toDelete[i]] = model[toDelete[i]];
            model.erase(toDelete[i]);
        }
        return true;
    } //----- Fin de Do

    bool Delete::Undo ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        undone = true;
        for(unsigned int i=0; i<toDelete.size(); i++)
        {
            model[toDelete[i]] = mapObject[toDelete[i]];
        }
        mapObject.clear();
        return true;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Delete::Delete ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Delete>" << endl;
    #endif
        undone = false;
        istringstream iss(data);
        do
        {
            string sub;
            iss >> sub;
            if(sub != "")
            {
                toDelete.push_back(sub);
            }
        } while (iss);
    } //----- Fin de Delete


    Delete::~Delete ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Delete>" << endl;
    #endif
        for(it_model i = mapObject.begin(); i != mapObject.end(); i++)
        {
            delete i->second;
        }
        mapObject.clear();
    } //----- Fin de ~Delete


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
