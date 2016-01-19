
    /*************************************************************************
                               Segment  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Segment> (fichier Segment) --------------
    #if ! defined ( SEGMENT_H )
    #define SEGMENT_H

    //--------------------------------------------------- Interfaces utilisées
    #include "SimpleObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Segment>
    //
    //
    //------------------------------------------------------------------------

    class Segment : public SimpleObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        void display() const;

    //------------------------------------------------- Surcharge d'opérateurs
        Segment & operator = ( const Segment & unSegment );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Segment ( const Segment & unSegment );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Segment ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Segment ( );
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

    //----------------------------------------- Types dépendants de <Segment>

    #endif // SEGMENT_H
