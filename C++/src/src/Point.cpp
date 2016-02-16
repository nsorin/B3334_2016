
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
    #include "../header/Point.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    int Point::GetX () const
    {
        return x;
    } //----- Fin de GetX

    int Point::GetY () const
    {
        return y;
    } //----- Fin de GetY

    void Point::SetX(int x)
    {
        this->x = x;
    } //----- Fin de SetX

    void Point::SetY(int y)
    {
        this->y = y;
    } //----- Fin de SetY

    void Point::Move ( int dx, int dy )
    {
        x+=dx;
        y+=dy;
    } //----- Fin de Move

    //------------------------------------------------- Surcharge d'opérateurs

    Point & Point::operator = ( const Point & unPoint )
    {
        this->x = unPoint.x;
        this->y = unPoint.y;
        return *this;
    } //----- Fin de operator =

    bool Point::operator==(const Point & unPoint)
    {
        return (unPoint.GetX()==this->GetX() && unPoint.GetY()==this->GetY());
    } //----- Fin de operator ==

    //-------------------------------------------- Constructeurs - destructeur
    Point::Point ( const Point & unPoint ) : x(unPoint.GetX()), y(unPoint.GetY())
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Point>" << endl;
    #endif
    } //----- Fin de Point (constructeur de copie)


    Point::Point ( int x1, int y1 ) : x(x1), y(y1)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Point>" << endl;
    #endif
    } //----- Fin de Point


    Point::~Point ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Point>" << endl;
    #endif
    } //----- Fin de ~Point


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
