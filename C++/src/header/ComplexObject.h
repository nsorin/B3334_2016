
    /*************************************************************************
                               ComplexObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <ComplexObject> (fichier ComplexObject) --------------
    #if ! defined ( COMPLEXOBJECT_H )
    #define COMPLEXOBJECT_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <ComplexObject>
    //
    //
    //------------------------------------------------------------------------

    class ComplexObject
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
        ComplexObject & operator = ( const ComplexObject & unComplexObject );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        ComplexObject ( const ComplexObject & unComplexObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        ComplexObject ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~ComplexObject ( );
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

    //----------------------------------------- Types dépendants de <ComplexObject>

    #endif // COMPLEXOBJECT_H
    