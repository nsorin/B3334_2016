
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
    bool Rectangle::Contains ( Point & p ) const
    {
        int minX = min(tabPoints[0].GetX(), tabPoints[1].GetX());
        int maxX = max(tabPoints[0].GetX(), tabPoints[1].GetX());
        int minY = min(tabPoints[0].GetY(), tabPoints[1].GetY());
        int maxY = max(tabPoints[0].GetY(), tabPoints[1].GetY());
        return (p.GetX() <= maxX && p.GetX() >= minX && p.GetY() <= maxY && p.GetY() >= minY);
    } //----- Fin de Contains


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Rectangle::Rectangle (string name, int x1, int y1, int x2, int y2) : SimpleObject(name, 2)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Rectangle>" << endl;
    #endif
        tabPoints[0].SetX(x1);
        tabPoints[0].SetY(y1);
        tabPoints[1].SetX(x2);
        tabPoints[1].SetY(y2);
    } //----- Fin de Rectangle


    Rectangle::~Rectangle ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Rectangle>" << endl;
    #endif
    } //----- Fin de ~Rectangle


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & Rectangle::doPrint(ostream & os) const
    {
        os << "R ";
        os << name << " ";
        for(unsigned int i = 0; i<nPoints; i++)
        {
            os << tabPoints[i].GetX() << " " << tabPoints[i].GetY() << " ";
        }
        os << endl;
        return os;
    }

    Object * Rectangle::clone()
    {
        Object* o = new Rectangle(name, tabPoints[0].GetX(), tabPoints[0].GetY(), tabPoints[1].GetX(), tabPoints[1].GetY());
        return o;
    }
