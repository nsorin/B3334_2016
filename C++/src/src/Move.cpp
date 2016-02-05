
    /*************************************************************************
                               Move  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Move> (fichier Move) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Move.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques

    bool Move::Do ( map<string, Object*> & model )
    {
        undone = false;
        if ( model.find(objectName) == model.end() )
        {
            return false;
        }
        else
        {
            model[objectName]->Move(dx, dy);
            return true;
        }
    } //----- Fin de Do

    bool Move::Undo ( map<string, Object*> & model )
    {
        undone = true;
        if ( model.find(objectName) == model.end() )
        {
            return false;
        }
        else
        {
            model[objectName]->Move(-1*dx, -1*dy);
            return true;
        }
    } //----- Fin de Undo

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Move::Move ( string & data )
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Move>" << endl;
    #endif
        undone = false;
        istringstream iss(data);
        iss >> objectName;
        iss >> dx;
        iss >> dy;
    } //----- Fin de Move


    Move::~Move ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Move>" << endl;
    #endif
    } //----- Fin de ~Move


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
