
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
    bool Segment::Contains ( Point & p ) const
    // Algorithme :
    //
    {
        int dy = p.GetY() - tabPoints[0].GetY();
        int dx = p.GetX() - tabPoints[0].GetX();
        int dyTh = tabPoints[1].GetY() - tabPoints[0].GetY();
        int dxTh = tabPoints[1].GetX() - tabPoints[0].GetX();

        int crossProduct = dy*dxTh - dx*dyTh;
        if(crossProduct != 0) //Remplacer par tolérance ?
        {
            return false;
        }
        int dotProduct = dx*dxTh + dy*dyTh;
        if(dotProduct < 0)
        {
            return false;
        }
        int squareLength = dxTh*dxTh + dyTh*dyTh;
        if(dotProduct > squareLength)
        {
            return false;
        }
        return true;
    } //----- Fin de Contains

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Segment::Segment (string name, int x1, int y1, int x2, int y2) : SimpleObject(name, 2)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Segment>" << endl;
    #endif
        tabPoints[0].SetX(x1);
        tabPoints[0].SetY(y1);
        tabPoints[1].SetX(x2);
        tabPoints[1].SetY(y2);
    } //----- Fin de Segment


    Segment::~Segment ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Segment>" << endl;
    #endif

    } //----- Fin de ~Segment


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & Segment::doPrint(ostream & os) const
    {
        os << "S ";
        os << name << " ";
        for(unsigned int i = 0; i<nPoints; i++)
        {
            os << tabPoints[i].GetX() << " " << tabPoints[i].GetY() << " ";
        }
        os << endl;
        return os;
    }

    Object * Segment::clone()
    {
        Object* o = new Segment(name, tabPoints[0].GetX(), tabPoints[0].GetY(), tabPoints[1].GetX(), tabPoints[1].GetY());
        return o;
    }
