
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
    #include <string>
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
        void Display() const;
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        //UnionObject & operator = ( const UnionObject & unUnionObject );
        // Mode d'emploi :
        //
        // Contrat :
        //

        friend std::ostream & operator<< (std::ostream & stream, const UnionObject & object);


    //-------------------------------------------- Constructeurs - destructeur
        UnionObject ( const UnionObject & unUnionObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        UnionObject (std::string name);
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
