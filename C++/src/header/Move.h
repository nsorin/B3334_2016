
    /*************************************************************************
                               Move  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Move> (fichier Move) --------------
    #if ! defined ( MOVE_H )
    #define MOVE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Move>
    //
    //
    //------------------------------------------------------------------------

    class Move : public Command
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
        //Move & operator = ( const Move & unMove );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Move ( const Move & unMove );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Move ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Move ( );
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
    std::string objectName;
    int dx;
    int dy;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Move>

    #endif // MOVE_H
