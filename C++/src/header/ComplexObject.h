
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
        std::vector<Object*> GetTabObjects() const;
        // Mode d'emploi :
        //

        void AddObject(Object * o);
        // Mode d'emploi :
        //

        void ClearObjects();
        // Mode d'emploi :
        //

        void Move(int dx, int dy);
        // Mode d'emploi :
        //

        virtual bool Contains(Point & p) const;
        // Mode d'emploi :
        //

        virtual std::ostream & doPrint(std::ostream & os) const;
        // Mode d'emploi :
        //

        virtual Object * clone();

    //------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, const ComplexObject & object);


    //-------------------------------------------- Constructeurs - destructeur
        ComplexObject ( std::string n = "" );
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
    std::vector<Object*> tabObjects;

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <ComplexObject>

    #endif // COMPLEXOBJECT_H
