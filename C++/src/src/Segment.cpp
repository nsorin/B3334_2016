
    /*************************************************************************
                               Segment  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Segment> (fichier Segment) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Segment.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void Segment::Display() const
    {

    }

    //------------------------------------------------- Surcharge d'opérateurs
    /*Segment & Segment::operator = ( const Segment & unSegment )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Segment::Segment ( const Segment & unSegment )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Segment>" << endl;
    #endif
        this->name = unSegment.name;
        tabPoints = new Point[2];
        tabPoints[0] = unSegment.tabPoints[0];
        tabPoints[1] = unSegment.tabPoints[1];
    } //----- Fin de Segment (constructeur de copie)


    Segment::Segment (string name, int x1, int y1, int x2, int y2)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Segment>" << endl;
    #endif
        Point p1(x1,y1);
        Point p2(x2,y2);
        this->name = name;
        tabPoints = new Point[2];
        tabPoints[0] = p1;
        tabPoints[1] = p2;
    } //----- Fin de Segment


    Segment::~Segment ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Segment>" << endl;
    #endif
        delete [] this->tabPoints;
    } //----- Fin de ~Segment


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
