
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
        virtual bool Contains(Point & p) const;
        // Mode d'emploi :
        //

        void Display() const;
        // Mode d'emploi :
        //

        virtual std::ostream & doPrint(std::ostream & os) const;

        virtual Object * clone();

    //------------------------------------------------- Surcharge d'opérateurs
        friend std::ostream & operator<< (std::ostream & stream, const UnionObject & object);


    //-------------------------------------------- Constructeurs - destructeur
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
