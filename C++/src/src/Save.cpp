
    /*************************************************************************
                               Save  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Save> (fichier Save) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Save.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void Save::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool Save::Do ( map<string, Object> & model )
    // Algorithme :
    //
    {
        return true;
    } //----- Fin de Do

    bool Save::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        return true;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs
    /*Save & Save::operator = ( const Save & unSave )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Save::Save ( const Save & unSave )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Save>" << endl;
    #endif
    } //----- Fin de Save (constructeur de copie)


    Save::Save ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Save>" << endl;
    #endif
    } //----- Fin de Save


    Save::~Save ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Save>" << endl;
    #endif
    } //----- Fin de ~Save


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
