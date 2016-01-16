
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

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <AddRectangle>
    //
    //
    //------------------------------------------------------------------------

    class AddRectangle
    {
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste de paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        AddRectangle & operator = ( const AddRectangle & unAddRectangle );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        AddRectangle ( const AddRectangle & unAddRectangle );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        AddRectangle ( );
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

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <AddRectangle>

    #endif // ADDRECTANGLE_H
    