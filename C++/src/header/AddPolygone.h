
    /*************************************************************************
                               AddPolygone  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <AddPolygone> (fichier AddPolygone) --------------
    #if ! defined ( ADDPOLYGONE_H )
    #define ADDPOLYGONE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Add.h"
    #include "Polygone.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <AddPolygone>
    //
    //
    //------------------------------------------------------------------------

    class AddPolygone : public Add
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
        AddPolygone & operator = ( const AddPolygone & unAddPolygone );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        AddPolygone ( const AddPolygone & unAddPolygone );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        AddPolygone ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~AddPolygone ( );
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
    Polygone *object;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <AddPolygone>

    #endif // ADDPOLYGONE_H
