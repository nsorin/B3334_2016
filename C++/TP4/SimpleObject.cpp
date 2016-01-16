
    /*************************************************************************
                               SimpleObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <SimpleObject> (fichier SimpleObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "SimpleObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type SimpleObject::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    SimpleObject & SimpleObject::operator = ( const SimpleObject & unSimpleObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    SimpleObject::SimpleObject ( const SimpleObject & unSimpleObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <SimpleObject>" << endl;
    #endif
    } //----- Fin de SimpleObject (constructeur de copie)


    SimpleObject::SimpleObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <SimpleObject>" << endl;
    #endif
    } //----- Fin de SimpleObject


    SimpleObject::~SimpleObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <SimpleObject>" << endl;
    #endif
    } //----- Fin de ~SimpleObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    