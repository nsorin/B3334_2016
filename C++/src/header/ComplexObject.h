
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
    #include "Point.h"
    #include <vector>
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
        std::vector<Object> GetTabObjects() const;
        // Mode d'emploi :
        //

        void AddObject(Object o);
        // Mode d'emploi :
        //

        void Move(int dx, int dy);
        // Mode d'emploi :
        //

        bool Contains(Point * ) const;
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        //ComplexObject & operator = ( const ComplexObject & unComplexObject );
        // Mode d'emploi :
        //
        // Contrat :
        //

        friend std::ostream & operator<< (std::ostream & stream, const ComplexObject & object);


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
        std::vector<Object> tabObjects;
    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <ComplexObject>

    #endif // COMPLEXOBJECT_H
