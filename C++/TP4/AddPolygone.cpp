
    /*************************************************************************
                               AddPolygone  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <AddPolygone> (fichier AddPolygone) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "AddPolygone.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type AddPolygone::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    AddPolygone & AddPolygone::operator = ( const AddPolygone & unAddPolygone )
    // Algorithme :
    //
    {
    } //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    AddPolygone::AddPolygone ( const AddPolygone & unAddPolygone )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <AddPolygone>" << endl;
    #endif
    } //----- Fin de AddPolygone (constructeur de copie)


    AddPolygone::AddPolygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddPolygone>" << endl;
    #endif
    } //----- Fin de AddPolygone


    AddPolygone::~AddPolygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddPolygone>" << endl;
    #endif
    } //----- Fin de ~AddPolygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    