
    /*************************************************************************
                               AddRectangle  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <AddRectangle> (fichier AddRectangle) --------------
    #if ! defined ( ADDRECTANGLE_H )
    #define ADDRECTANGLE_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Add.h"
    #include "Rectangle.h"

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <AddRectangle>
    //
    //
    //------------------------------------------------------------------------

    class AddRectangle : public Add
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        virtual void Display ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Do ( std::map<std::string, Object*> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual bool Undo ( std::map<std::string, Object*> & model );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
        AddRectangle ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~AddRectangle ( );
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
    Rectangle *object;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <AddRectangle>

    #endif // ADDRECTANGLE_H
