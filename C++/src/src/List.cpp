
    /*************************************************************************
                               List  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <List> (fichier List) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/List.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type List::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    /*List & List::operator = ( const List & unList )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    List::List ( const List & unList )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <List>" << endl;
    #endif
    } //----- Fin de List (constructeur de copie)


    List::List ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <List>" << endl;
    #endif
    } //----- Fin de List


    List::~List ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <List>" << endl;
    #endif
    } //----- Fin de ~List


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
