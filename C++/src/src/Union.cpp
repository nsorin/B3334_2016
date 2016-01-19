
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
    void Union::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool Union::Do()
    // Algorithme :
    //
    {
        if ( model.find(components[i]) == model.end() ) 
        {
            object = new UnionObject(name);
            for(unsigned int i=0; i<components.size(); i++)
            {
                if ( model.find(components[i]) == model.end() ) 
                {
                    object.AddObject(model[components[i]]);
                } 
                else 
                {
                    delete object;
                    return false;
                }
            }
            return true;
        } 
        else 
        {
            return false;
        }
    } //----- Fin de Do

    bool Union::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        model[name].erase();
        delete object;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs
    /*Union & Union::operator = ( const Union & unUnion )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Union::Union ( const Union & unUnion )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Union>" << endl;
    #endif
    } //----- Fin de Union (constructeur de copie)


    Union::Union ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Union>" << endl;
    #endif
        istringstream iss(data);
        iss >> name;

        do
        {
            string n;
            iss >> n;
            components.push_back(n);
        } while (iss);
    } //----- Fin de Union


    Union::~Union ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Union>" << endl;
    #endif
        if(object)
        {
            delete object;
        }
    } //----- Fin de ~Union


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
