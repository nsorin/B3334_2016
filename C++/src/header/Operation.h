
    /*************************************************************************
                               Operation  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Operation> (fichier Operation) --------------
    #if ! defined ( OPERATION_H )
    #define OPERATION_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Operation>
    //
    //
    //------------------------------------------------------------------------

    class Operation : public Command
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        virtual void Display ( ) = 0;
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Do ( std::map<std::string, Object*> & model ) = 0;
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Undo ( std::map<std::string, Object*> & model ) = 0;
        // Mode d'emploi :
        //
        // Contrat :
        //



    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
        Operation ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Operation ( );
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

    //----------------------------------------- Types dépendants de <Operation>

    #endif // OPERATION_H
