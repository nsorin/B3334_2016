
    /*************************************************************************
                               Clear  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Clear> (fichier Clear) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Clear.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void Clear::Display ( )
    // Algorithme :
    //
    {
        cout << SUCCESS << endl;
    } //----- Fin de Display

    bool Clear::Do ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        mapObject = model;
        model.clear();
        Display();
        return true;
    } //----- Fin de Display

    bool Clear::Undo ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        model = mapObject;
        mapObject.clear();
        Display();
        return true;
    } //----- Fin de Display


    //------------------------------------------------- Surcharge d'opérateurs
    /*Clear & Clear::operator = ( const Clear & unClear )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Clear::Clear ( const Clear & unClear )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Clear>" << endl;
    #endif
    } //----- Fin de Clear (constructeur de copie)


    Clear::Clear ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Clear>" << endl;
    #endif
    } //----- Fin de Clear


    Clear::~Clear ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Clear>" << endl;
    #endif
        for(it_model i = mapObject.begin(); i != mapObject.end(); i++)
        {
            delete i->second;
        }
    } //----- Fin de ~Clear


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
