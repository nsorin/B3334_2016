
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
    #include "Object.h"
    #include "Point.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <SimpleObject>
    //
    //
    //------------------------------------------------------------------------

    class SimpleObject : public Object
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        virtual bool Contains(Point & p) const;
        // Mode d'emploi :
        //

        Point * GetTabPoints( ) const;
        // Mode d'emploi :
        //

        unsigned int GetSize() const;
        // Mode d'emploi :
        //

        void Move(int dx, int dy);
        // Mode d'emploi :
        //

        virtual std::ostream & doPrint(std::ostream & os) const;

        virtual Object * clone();

    //------------------------------------------------- Surcharge d'opérateurs
        //SimpleObject & operator = ( const SimpleObject & unSimpleObject );
        // Mode d'emploi :
        //
        // Contrat :
        //

        friend std::ostream & operator<< (std::ostream & stream, const SimpleObject & object);


    //-------------------------------------------- Constructeurs - destructeur
        SimpleObject ( const SimpleObject & unSimpleObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        SimpleObject ( std::string n = "", unsigned int np = 2 );
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
        Point * tabPoints;
        unsigned int nPoints;

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <SimpleObject>

    #endif // SIMPLEOBJECT_H
