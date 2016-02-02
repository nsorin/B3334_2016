
    /*************************************************************************
                               Command  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Command> (fichier Command) --------------
    #if ! defined ( COMMAND_H )
    #define COMMAND_H

    //--------------------------------------------------- Interfaces utilisées
    #include <string>
    #include <map>
    #include <vector>
    #include <sstream>
    #include "Object.h"

    //------------------------------------------------------------- Constantes
    static std::string ERROR = "ERR";
    static std::string SUCCESS = "OK";

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Command>
    //
    //
    //------------------------------------------------------------------------

    class Command
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
        //Command & operator = ( const Command & unCommand );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Command ( const Command & unCommand );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Command ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Command ( );
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

    //----------------------------------------- Types dépendants de <Command>

    #endif // COMMAND_H
