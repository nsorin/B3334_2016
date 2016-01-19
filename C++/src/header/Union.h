
    /*************************************************************************
                               Union  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Union> (fichier Union) --------------
    #if ! defined ( UNION_H )
    #define UNION_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Operation.h"
    #include "UnionObject.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Union>
    //
    //
    //------------------------------------------------------------------------

    class Union : public Operation
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
        Union & operator = ( const Union & unUnion );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Union ( const Union & unUnion );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Union ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Union ( );
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
    UnionObject object;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Union>

    #endif // UNION_H
    