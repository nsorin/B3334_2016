
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

    /*ostream & operator<< (ostream & stream, const Segment & object)
    {
        stream << "S ";
        stream << object.GetName();
        for(unsigned int i = 0; i<object.GetSize(); i++)
        {
            stream << object.GetTabPoints()[i].GetX() << " " << object.GetTabPoints()[i].GetY() << " ";
        }
        stream << endl;
        return stream;
    }*/

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
        delete [] this->tabPoints;
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
