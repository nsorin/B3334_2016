
    /*************************************************************************
                               Save  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Save> (fichier Save) --------------
    #if ! defined ( SAVE_H )
    #define SAVE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Save>
    //
    //
    //------------------------------------------------------------------------

    class Save : public Command
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        virtual void Display ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Do ( std::map<std::string, Object*> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Undo ( std::map<std::string, Object*> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //



    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
        Save ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Save ( );
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

    //----------------------------------------- Types dépendants de <Save>

    #endif // SAVE_H
