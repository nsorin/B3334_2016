
    /*************************************************************************
                               Load  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Load> (fichier Load) --------------
    #if ! defined ( LOAD_H )
    #define LOAD_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Load>
    //
    //
    //------------------------------------------------------------------------

    class Load : public Command
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        //virtual void Display ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        //virtual bool Do ( std::map<std::string, Object> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //

        //virtual bool Undo ( std::map<std::string, Object> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //



    //------------------------------------------------- Surcharge d'opérateurs
        //Load & operator = ( const Load & unLoad );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Load ( const Load & unLoad );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Load ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Load ( );
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
    std::map<std::string, Object> mapObject;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Load>

    #endif // LOAD_H
