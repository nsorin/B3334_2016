
    /*************************************************************************
                               Object  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Object> (fichier Object) --------------
    #if ! defined ( OBJECT_H )
    #define OBJECT_H

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Object>
    //
    //
    //------------------------------------------------------------------------

    class Object
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        bool contains() const;
        // Mode d'emploi :
        //

        void move();
        // Mode d'emploi :
        //

        void display() const;
        // Mode d'emploi :
        //

        string getName() const;
        // Mode d'emploi :
        //

        void setName();
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        Object & operator = ( const Object & unObject );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        Object ( const Object & unObject );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        Object ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Object ( );
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
        string Name;
    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Object>

    #endif // OBJECT_H
