
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
    #include "Object.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <ComplexObject>
    //
    //
    //------------------------------------------------------------------------

    class ComplexObject : public Object
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        Object * getTabObjects() const;
        // Mode d'emploi :
        //

        void move();
        // Mode d'emploi :
        //

        bool contains() const;
        // Mode d'emploi :
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
        Object * tabObjects;
    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <ComplexObject>

    #endif // COMPLEXOBJECT_H
