
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
    #include <map>

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
        //virtual bool contains() const;
        // Mode d'emploi :
        //

        virtual void Move( int dx, int dy );
        // Mode d'emploi :
        //

        //virtual void display() const;
        // Mode d'emploi :
        //

        std::string GetName( ) const;
        // Mode d'emploi :
        //

        //void setName(string name){this->name = name;};
        // Mode d'emploi :
        //

    //------------------------------------------------- Surcharge d'opérateurs
        //Object & operator = ( const Object & unObject );
        // Mode d'emploi :
        //
        // Contrat :
        //

        friend std::ostream & operator<< (std::ostream & stream, Object & object);


    //-------------------------------------------- Constructeurs - destructeur
        Object ( const Object & unObject );
        // Mode d'emploi (constructeur de copie) :
        //

        Object ( std::string n = "undefined" );
        // Mode d'emploi :
        //

        virtual ~Object ( );
        // Mode d'emploi :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    private:
    //------------------------------------------------------- Méthodes privées
    virtual std::ostream & doPrint(std::ostream & os) const;

    protected:
    //----------------------------------------------------- Attributs protégés
        std::string name;

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Object>
    typedef std::map<std::string, Object*>::iterator it_model;

    #endif // OBJECT_H