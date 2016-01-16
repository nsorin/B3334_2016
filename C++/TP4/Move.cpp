
    /*************************************************************************
                               Move  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Move> (fichier Move) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Move.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Move::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Move & Move::operator = ( const Move & unMove )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Move::Move ( const Move & unMove )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Move>" << endl;
    #endif
    } //----- Fin de Move (constructeur de copie)


    Move::Move ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Move>" << endl;
    #endif
    } //----- Fin de Move


    Move::~Move ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Move>" << endl;
    #endif
    } //----- Fin de ~Move


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    