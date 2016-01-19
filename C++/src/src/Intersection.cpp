
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
    void Intersection::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool Intersection::Do ( map<string, Object> & model )
    // Algorithme :
    //
    {
        if ( model.find(components[i]) == model.end() ) 
        {
            object = new InterObject(name);
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

    bool Intersection::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        model[object->GetName()].erase();
        delete object;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs
    /*Intersection & Intersection::operator = ( const Intersection & unIntersection )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Intersection::Intersection ( const Intersection & unIntersection )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Intersection>" << endl;
    #endif
    } //----- Fin de Intersection (constructeur de copie)


    Intersection::Intersection ( string & data, map<string, Object> & model )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Intersection>" << endl;
    #endif
        istringstream iss(data);
        iss >> name;

        do
        {
            string n;
            iss >> n;
            components.push_back(n);
        } while (iss);
    } //----- Fin de Intersection


    Intersection::~Intersection ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Intersection>" << endl;
    #endif
        if(object)
        {
            delete object;
        }
    } //----- Fin de ~Intersection


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
