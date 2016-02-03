
    /*************************************************************************
                               Rectangle  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Rectangle> (fichier Rectangle) --------------
    #if ! defined ( RECTANGLE_H )
    #define RECTANGLE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "SimpleObject.h"
    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Rectangle>
    //
    //
    //------------------------------------------------------------------------

    class Rectangle : public SimpleObject
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        //void display() const;
    virtual bool Contains(Point & p) const;
    // Mode d'emploi :
    //

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

    //------------------------------------------------- Surcharge d'opérateurs
        friend std::ostream & operator<< (std::ostream & stream, const Rectangle & object);

    //-------------------------------------------- Constructeurs - destructeur
        Rectangle (std::string name, int x1, int y1, int x2, int y2);
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Rectangle ( );
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

    //----------------------------------------- Types dépendants de <Rectangle>

    #endif // RECTANGLE_H
