
    /*************************************************************************
                               Rectangle  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Rectangle> (fichier Rectangle) --------------
    #if ! defined ( RECTANGLE_H )
    #define RECTANGLE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "SimpleObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Rectangle>
    //
    //
    //------------------------------------------------------------------------

    class Rectangle : public SimpleObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        void display() const;


    //------------------------------------------------- Surcharge d'opérateurs
        Rectangle & operator = ( const Rectangle & unRectangle );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Rectangle ( const Rectangle & unRectangle );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Rectangle ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Rectangle ( );
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

    //----------------------------------------- Types dépendants de <Rectangle>

    #endif // RECTANGLE_H
