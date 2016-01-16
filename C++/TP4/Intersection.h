
    /*************************************************************************
                               Intersection  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Intersection> (fichier Intersection) --------------
    #if ! defined ( INTERSECTION_H )
    #define INTERSECTION_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Intersection>
    //
    //
    //------------------------------------------------------------------------

    class Intersection
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste de paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        Intersection & operator = ( const Intersection & unIntersection );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Intersection ( const Intersection & unIntersection );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Intersection ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Intersection ( );
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

    //----------------------------------------- Types dépendants de <Intersection>

    #endif // INTERSECTION_H
    