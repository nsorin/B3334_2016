
    /*************************************************************************
                               Operation  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Operation> (fichier Operation) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Operation.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Operation::Operation ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Operation>" << endl;
    #endif
    } //----- Fin de Operation


    Operation::~Operation ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Operation>" << endl;
    #endif
    } //----- Fin de ~Operation


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
