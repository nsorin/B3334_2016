
    /*************************************************************************
                               Delete  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Delete> (fichier Delete) --------------
    #if ! defined ( DELETE_H )
    #define DELETE_H

    //--------------------------------------------------- Interfaces utilisées
#include "Command.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Delete>
    //
    //
    //------------------------------------------------------------------------

    class Delete : public Command
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste de paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        Delete & operator = ( const Delete & unDelete );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Delete ( const Delete & unDelete );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Delete ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Delete ( );
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
    std::vector<std::string> toDelete;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Delete>

    #endif // DELETE_H
    