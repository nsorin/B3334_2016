
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
    //
    //
    //------------------------------------------------------------------------

    class Point
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        int GetX() const{return x;}
        int GetY() const{return y;}
        void SetX(int x){this->x = x;}
        void SetY(int y){this->y = y;}
        void Move(int dx, int dy){x+=dx; y+=dy;}

    //------------------------------------------------- Surcharge d'opérateurs
        Point & operator=( const Point & unPoint ) {this->x = unPoint.x; this->y = unPoint.y; return *this;}
    //-------------------------------------------- Constructeurs - destructeur
        Point ( const Point & unPoint ):x(unPoint.GetX()), y(unPoint.GetY()){}
        // Mode d'emploi (constructeur de copie) :
        //

        Point (int x1 = 0, int y1 = 0) : x(x1), y(y1){}
        // Mode d'emploi :
        //

        virtual ~Point ( ) {}
        // Mode d'emploi :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    private:
    //------------------------------------------------------- Méthodes privées

    protected:
    //----------------------------------------------------- Attributs protégés

    private:
    //------------------------------------------------------- Attributs privés
        int x;
        int y;
    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Point>

    #endif // POINT_H
