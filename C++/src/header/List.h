
    /*************************************************************************
                               List  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <List> (fichier List) --------------
    #if ! defined ( LIST_H )
    #define LIST_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"

    //---------1---------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <List>
    //
    //
    //------------------------------------------------------------------------

    class List : public Command
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
        List & operator = ( const List & unList );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        List ( const List & unList );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        List ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~List ( );
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

    //----------------------------------------- Types dépendants de <List>

    #endif // LIST_H
    