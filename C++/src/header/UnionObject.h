
    /*************************************************************************
                               UnionObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <UnionObject> (fichier UnionObject) --------------
    #if ! defined ( UNIONOBJECT_H )
    #define UNIONOBJECT_H

    //--------------------------------------------------- Interfaces utilisées
    #include "ComplexObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <UnionObject>
    //
    //
    //------------------------------------------------------------------------

    class UnionObject : public ComplexObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        //void display() const;
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        //UnionObject & operator = ( const UnionObject & unUnionObject );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        UnionObject ( const UnionObject & unUnionObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        UnionObject ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~UnionObject ( );
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

    //----------------------------------------- Types dépendants de <UnionObject>

    #endif // UNIONOBJECT_H
