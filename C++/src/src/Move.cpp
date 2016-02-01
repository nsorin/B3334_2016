
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
    void Move::Display ( )
    // Algorithme :
    //
    {

    } //----- Fin de Display

    bool Move::Do ( map<string, Object> & model )
    // Algorithme :
    //
    {
        if ( model.find(objectName) == model.end() )
        {
            return false;
        }
        else
        {
            model[objectName].Move(dx, dy);
            return true;
        }
    } //----- Fin de Do

    bool Move::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        if ( model.find(objectName) == model.end() )
        {
            return false;
        }
        else
        {
            model[objectName].Move(-1*dx, -1*dy);
            return true;
        }
    } //----- Fin de Undo

    //------------------------------------------------- Surcharge d'opérateurs
    /*Move & Move::operator = ( const Move & unMove )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Move::Move ( const Move & unMove )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Move>" << endl;
    #endif
        this->objectName = unMove.objectName;
        this->dx = unMove.dx;
        this->dy = unMove.dy;
    } //----- Fin de Move (constructeur de copie)


    Move::Move ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Move>" << endl;
    #endif
        istringstream iss(data);
        iss >> objectName;
        iss >> dx;
        iss >> dy;
    } //----- Fin de Move


    Move::~Move ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Move>" << endl;
    #endif
    } //----- Fin de ~Move


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
