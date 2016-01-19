
    /*************************************************************************
                               AddSegment  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <AddSegment> (fichier AddSegment) --------------
    #if ! defined ( ADDSEGMENT_H )
    #define ADDSEGMENT_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Add.h"
    #include "Segment.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <AddSegment>
    //
    //
    //------------------------------------------------------------------------

    class AddSegment : public Add
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        virtual void Display ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Do ( std::map<std::string, Object> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Undo ( std::map<std::string, Object> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        AddSegment & operator = ( const AddSegment & unAddSegment );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        AddSegment ( const AddSegment & unAddSegment );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        AddSegment ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~AddSegment ( );
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
    Segment *object;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <AddSegment>

    #endif // ADDSEGMENT_H
    