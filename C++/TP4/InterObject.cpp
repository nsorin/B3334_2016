
    /*************************************************************************
                               InterObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <InterObject> (fichier InterObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "InterObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type InterObject::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    InterObject & InterObject::operator = ( const InterObject & unInterObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    InterObject::InterObject ( const InterObject & unInterObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <InterObject>" << endl;
    #endif
    } //----- Fin de InterObject (constructeur de copie)


    InterObject::InterObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <InterObject>" << endl;
    #endif
    } //----- Fin de InterObject


    InterObject::~InterObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <InterObject>" << endl;
    #endif
    } //----- Fin de ~InterObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    