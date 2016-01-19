
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
        Point & operator = ( const Point & unPoint );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Point ( const Point & unPoint );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Point ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Point ( );
        // Mode d'emploi :
        //
        // Contrat :
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
