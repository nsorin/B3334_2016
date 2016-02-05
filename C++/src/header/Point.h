/*************************************************************************
                            Point  -  description
                             -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <Point> (fichier Point) --------------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Point>
// Classe caractérisant un point
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    int GetX() const;

    int GetY() const;

    void SetX(int x);

    void SetY(int y);

    void Move(int dx, int dy);

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator=( const Point & unPoint );

    bool operator==(const Point & unPoint);

//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & unPoint );

    Point (int x1 = 0, int y1 = 0);

    virtual ~Point ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    int x; //abscisse du point
    int y; //ordonné du point
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées
//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
