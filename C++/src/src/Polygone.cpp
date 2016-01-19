
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

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void Polygone::Display() const
    {

    }

    bool Polygone::IsConvex() const
    {
        return true;
    }

    //------------------------------------------------- Surcharge d'opérateurs
    Polygone & Polygone::operator = ( const Polygone & unPolygone )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Polygone::Polygone ( const Polygone & unPolygone )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Polygone>" << endl;
    #endif        
    } //----- Fin de Polygone (constructeur de copie)


    Polygone::Polygone( vector<Point> & points )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Polygone>" << endl;
    #endif
        int taille = points.size();
        this->tabPoints = new Point[taille];
        for(int i=0;i<taille;i++)
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
        delete [] tabPoints;
    } //----- Fin de ~Polygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
