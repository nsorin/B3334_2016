
    /*************************************************************************
                               SimpleObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <SimpleObject> (fichier SimpleObject) --------------
    #if ! defined ( SIMPLEOBJECT_H )
    #define SIMPLEOBJECT_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <SimpleObject>
    //
    //
    //------------------------------------------------------------------------

    class SimpleObject
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
        SimpleObject & operator = ( const SimpleObject & unSimpleObject );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        SimpleObject ( const SimpleObject & unSimpleObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        SimpleObject ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~SimpleObject ( );
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

    //----------------------------------------- Types dépendants de <SimpleObject>

    #endif // SIMPLEOBJECT_H
    