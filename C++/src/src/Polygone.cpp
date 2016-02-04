
    /*************************************************************************
                               Polygone  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Polygone> (fichier Polygone) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>
    #include <vector>

    //------------------------------------------------------ Include personnel
    #include "../header/Polygone.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- doubleiables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool Polygone::Contains ( Point & p ) const
    // Algorithme :
    //
    {
        double pos = 0;
        double neg = 0;
        for (unsigned i = 0; i<nPoints; i++)
        {
            if (tabPoints[i] == p)
            {
                return true;
            }
            double x1 = tabPoints[i].GetX();
            double y1 = tabPoints[i].GetY();

            int i2 = i < nPoints - 1 ? i + 1 : 0;

            double x2 = tabPoints[i2].GetX();
            double y2 = tabPoints[i2].GetY();

            double x = p.GetX();
            double y = p.GetY();

            double d = (x - x1)*(y2 - y1) - (y - y1)*(x2 - x1);

            if (d > 0) pos++;
            if (d < 0) neg++;

            //If the sign changes, then point is outside
            if (pos > 0 && neg > 0)
            {
                return false;
            }
        }
        return true;
    } //----- Fin de Contains

    void Polygone::Display() const
    {

    }

    bool Polygone::IsConvex() const
    {
        if (nPoints<4)
        {
           return true;
        }
        bool sign=false;
        for(unsigned i=0;i<nPoints;i++)
        {
            double dx1,dx2,dy1,dy2;
            if(i<nPoints-2)
            {
                dx1 = tabPoints[i+2].GetX()-tabPoints[i+1].GetX();
                dy1 = tabPoints[i+2].GetY()-tabPoints[i+1].GetY();
                dx2 = tabPoints[i+1].GetX()-tabPoints[i].GetX();
                dy2 = tabPoints[i+1].GetY()-tabPoints[i].GetY();
            }
            else if(i==nPoints-2)
            {
                dx1 = tabPoints[0].GetX()-tabPoints[i+1].GetX();
                dy1 = tabPoints[0].GetY()-tabPoints[i+1].GetY();
                dx2 = tabPoints[i+1].GetX()-tabPoints[i].GetX();
                dy2 = tabPoints[i+1].GetY()-tabPoints[i].GetY();
            }
            else
            {
                dx1 = tabPoints[1].GetX()-tabPoints[0].GetX();
                dy1 = tabPoints[1].GetY()-tabPoints[0].GetY();
                dx2 = tabPoints[0].GetX()-tabPoints[i].GetX();
                dy2 = tabPoints[0].GetY()-tabPoints[i].GetY();
            }
            double crossproduct = dx1*dy2 - dy1*dx2;
            if (i==0)
            {
               sign = crossproduct>0;
            }
            else
            {
               if (sign != (crossproduct>0))
               {
                   return false;
               }
            }
        }
        return true;
    }

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Polygone::Polygone( string & n, vector<Point> & points ) : SimpleObject(n, points.size())
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Polygone>" << endl;
    #endif
        for(unsigned int i=0;i<nPoints;i++)
        {
            tabPoints[i] = points[i];
        }
    } //----- Fin de Polygone


    Polygone::~Polygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Polygone>" << endl;
    #endif
    } //----- Fin de ~Polygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & Polygone::doPrint(ostream & os) const
    {
        os << "PC ";
        os << name<< " ";
        for(unsigned int i = 0; i<nPoints; i++)
        {
            os << tabPoints[i].GetX() << " " << tabPoints[i].GetY() << " ";
        }
        os << endl;
        return os;
    }

    Object * Polygone::clone()
    {
        vector<Point> temp;
        for(unsigned int i = 0; i <nPoints; i++)
        {
            temp.push_back(tabPoints[i]);
        }
        Object* o = new Polygone(name, temp);
        return o;
    }
