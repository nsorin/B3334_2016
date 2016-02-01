
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
        Point * GetTabPoints() const;
        // Mode d'emploi :
        //

        //void move();
        // Mode d'emploi :
        //

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

        SimpleObject ( std::string n = "" );
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

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <SimpleObject>

    #endif // SIMPLEOBJECT_H
