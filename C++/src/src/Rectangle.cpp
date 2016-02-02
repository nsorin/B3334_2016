
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

    /*ostream & operator<< (ostream & stream, const Rectangle & object)
    {
        stream << "R ";
        stream << object.GetName();
        for(unsigned int i = 0; i<object.GetSize(); i++)
        {
            stream << object.GetTabPoints()[i].GetX() << " " << object.GetTabPoints()[i].GetY() << " ";
        }
        stream << endl;
        return stream;
    }*/


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


    Rectangle::Rectangle (string name, int x1, int y1, int x2, int y2) : SimpleObject(name, 2)
    // Algorithme :
    //
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
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Rectangle>" << endl;
    #endif
        delete [] tabPoints;
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
