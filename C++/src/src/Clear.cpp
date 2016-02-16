
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
    bool Clear::Do ( map<string, Object*> & model )
    {
        undone = false;
        mapObject = model;
        model.clear();
        return true;
    } //----- Fin de Display

    bool Clear::Undo ( map<string, Object*> & model )
    {
        undone = true;
        model = mapObject;
        mapObject.clear();
        return true;
    } //----- Fin de Display


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Clear::Clear ( )
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Clear>" << endl;
    #endif
        undone = false;
    } //----- Fin de Clear


    Clear::~Clear ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Clear>" << endl;
    #endif
        for(it_model i = mapObject.begin(); i != mapObject.end(); i++)
        {
            delete i->second;
        }
        mapObject.clear();
    } //----- Fin de ~Clear


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
