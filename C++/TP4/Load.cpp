
    /*************************************************************************
                               Load  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Load> (fichier Load) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Load.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Load::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Load & Load::operator = ( const Load & unLoad )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Load::Load ( const Load & unLoad )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Load>" << endl;
    #endif
    } //----- Fin de Load (constructeur de copie)


    Load::Load ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Load>" << endl;
    #endif
    } //----- Fin de Load


    Load::~Load ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Load>" << endl;
    #endif
    } //----- Fin de ~Load


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    