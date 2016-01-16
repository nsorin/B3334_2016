
    /*************************************************************************
                               Redo  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Redo> (fichier Redo) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Redo.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Redo::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Redo & Redo::operator = ( const Redo & unRedo )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Redo::Redo ( const Redo & unRedo )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Redo>" << endl;
    #endif
    } //----- Fin de Redo (constructeur de copie)


    Redo::Redo ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Redo>" << endl;
    #endif
    } //----- Fin de Redo


    Redo::~Redo ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Redo>" << endl;
    #endif
    } //----- Fin de ~Redo


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    