
    /*************************************************************************
                               Load  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //-------------- Interface de la classe <Load> (fichier Load) --------------
    #if ! defined ( LOAD_H )
    #define LOAD_H

    //--------------------------------------------------- Interfaces utilisées
    #include "Command.h"
    #include "AddSegment.h"
    #include "AddPolygone.h"
    #include "AddRectangle.h"
    #include "Union.h"
    #include "Intersection.h"
    #include <fstream>

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <Load>
    //
    //
    //------------------------------------------------------------------------

    class Load : public Command
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
        Load ( std::string & data );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~Load ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    private:
    //------------------------------------------------------- Méthodes privées
    bool parseLine(std::string & line);

    protected:
    //----------------------------------------------------- Attributs protégés

    private:
    //------------------------------------------------------- Attributs privés
    std::string fileName;
    std::map<std::string, Object*> mapObjects;
    std::map<std::string, Object*> oldObjects;

    std::vector<ComplexObject*> ops;
    std::vector<std::map<std::string, Object*> > tempObjects;
    unsigned int opIndex;

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    };

    //----------------------------------------- Types dépendants de <Load>

    #endif // LOAD_H
