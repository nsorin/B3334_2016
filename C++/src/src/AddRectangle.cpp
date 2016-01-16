
    /*************************************************************************
                               AddRectangle  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <AddRectangle> (fichier AddRectangle) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/AddRectangle.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type AddRectangle::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{
    //} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    /*AddRectangle & AddRectangle::operator = ( const AddRectangle & unAddRectangle )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    AddRectangle::AddRectangle ( const AddRectangle & unAddRectangle )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <AddRectangle>" << endl;
    #endif
    } //----- Fin de AddRectangle (constructeur de copie)


    AddRectangle::AddRectangle ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddRectangle>" << endl;
    #endif
    } //----- Fin de AddRectangle


    AddRectangle::~AddRectangle ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddRectangle>" << endl;
    #endif
    } //----- Fin de ~AddRectangle


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
