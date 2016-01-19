
    /*************************************************************************
                               Rectangle  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Rectangle> (fichier Rectangle) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Rectangle.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type Rectangle::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    /*Rectangle & Rectangle::operator = ( const Rectangle & unRectangle )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Rectangle::Rectangle ( const Rectangle & unRectangle )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Rectangle>" << endl;
    #endif
        this->name = unRectangle.name;
        tabPoints = new Point[2];
        tabPoints[0] = unRectangle.tabPoints[0];
        tabPoints[1] = unRectangle.tabPoints[1];
    } //----- Fin de Rectangle (constructeur de copie)


    Rectangle::Rectangle (string name, int x1, int y1, int x2, int y2)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Rectangle>" << endl;
    #endif
        this->name = name;
        Point p1(x1,y1);
        Point p2(x2,y2);
        tabPoints = new Point[2];
        tabPoints[0] = p1;
        tabPoints[1] = p2;
    } //----- Fin de Rectangle


    Rectangle::~Rectangle ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Rectangle>" << endl;
    #endif
        delete [] this->tabPoints;
    } //----- Fin de ~Rectangle


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
