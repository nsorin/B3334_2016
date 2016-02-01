
    /*************************************************************************
                               Object  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Object> (fichier Object) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Object.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    string Object::GetName ( )
    // Algorithme :
    //
    {
        return name;
    } //----- Fin de GetName

    void Object::Move ( int dx, int dy )
    // Algorithme :
    //
    {

    } //----- Fin de GetName

    //------------------------------------------------- Surcharge d'opérateurs
    /*Object & Object::operator = ( const Object & unObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    Object::Object ( const Object & unObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Object>" << endl;
    #endif
    } //----- Fin de Object (constructeur de copie)


    Object::Object ( string n ) : name(n)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Object>" << endl;
    #endif
    } //----- Fin de Object


    Object::~Object ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Object>" << endl;
    #endif
    } //----- Fin de ~Object


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
