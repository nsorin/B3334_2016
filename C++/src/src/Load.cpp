
    /*************************************************************************
                               Load  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Load> (fichier Load) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Load.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void Load::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool Load::Do ( map<string, Object> & model )
    // Algorithme :
    //
    {
        return true;
    } //----- Fin de Do

    bool Load::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        return true;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs
    /*Load & Load::operator = ( const Load & unLoad )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Load::Load ( const Load & unLoad )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Load>" << endl;
    #endif
    } //----- Fin de Load (constructeur de copie)


    Load::Load ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Load>" << endl;
    #endif
    } //----- Fin de Load


    Load::~Load ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Load>" << endl;
    #endif
    } //----- Fin de ~Load


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
