
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
        int getX() const{return x;}
        int getY() const{return y;}
        void setX(int x){this->x = x;}
        void setY(int y){this->y = y;}


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
        Point ( const Point & unPoint ):x(unPoint.getX()), y(unPoint.getY()){}
        // Mode d'emploi (constructeur de copie) :
        //

        Point (int x1, int y1) : x(x1), y(y1){}
        // Mode d'emploi :
        //

        Point (){}
        // Mode d'emploi :
        //

        virtual ~Point ( );
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
