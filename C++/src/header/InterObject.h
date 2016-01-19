
    /*************************************************************************
                               InterObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <InterObject> (fichier InterObject) --------------
    #if ! defined ( INTEROBJECT_H )
    #define INTEROBJECT_H

    //--------------------------------------------------- Interfaces utilisées
    #include "ComplexObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <InterObject>
    //
    //
    //------------------------------------------------------------------------

    class InterObject : public ComplexObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        //void display() const;
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        //InterObject & operator = ( const InterObject & unInterObject );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        InterObject ( const InterObject & unInterObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        InterObject ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~InterObject ( );
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

    //----------------------------------------- Types dépendants de <InterObject>

    #endif // INTEROBJECT_H
