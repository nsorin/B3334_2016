
    /*************************************************************************
                               Polygone  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Polygone> (fichier Polygone) --------------
    #if ! defined ( POLYGONE_H )
    #define POLYGONE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "SimpleObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Polygone>
    //
    //
    //------------------------------------------------------------------------

    class Polygone : public SimpleObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        void Display() const;
        // Mode d'emploi :
        //

        bool IsConvex() const;
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        Polygone & operator = ( const Polygone & unPolygone );
        // Mode d'emploi :
        //
        // Contrat :
        //

        friend std::ostream & operator<< (std::ostream & stream, const Polygone & object);


    //-------------------------------------------- Constructeurs - destructeur
        Polygone ( const Polygone & unPolygone );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Polygone (std::string & n, std::vector<Point> & points);
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Polygone ( );
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

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Polygone>

    #endif // POLYGONE_H
