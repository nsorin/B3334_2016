
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

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Operation>
    //
    //
    //------------------------------------------------------------------------

    class Operation
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
        Operation & operator = ( const Operation & unOperation );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Operation ( const Operation & unOperation );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

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
    