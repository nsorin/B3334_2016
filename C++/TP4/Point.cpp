
    /*************************************************************************
                               Point  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Point> (fichier Point) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "Point.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Point::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    Point & Point::operator = ( const Point & unPoint )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    Point::Point ( const Point & unPoint )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Point>" << endl;
    #endif
    } //----- Fin de Point (constructeur de copie)


    Point::Point ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Point>" << endl;
    #endif
    } //----- Fin de Point


    Point::~Point ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Point>" << endl;
    #endif
    } //----- Fin de ~Point


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    