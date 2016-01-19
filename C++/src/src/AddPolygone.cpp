
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
    #include "../header/AddPolygone.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void AddPolygone::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    void AddPolygone::Do ( )
    // Algorithme :
    //
    {
        if ( model.find(object->GetName()) == model.end() ) 
        {
            model[object->GetName()] = object;
            return true;
        } 
        else 
        {
            return false;
        }
    } //----- Fin de Display

    void AddPolygone::Undo ( )
    // Algorithme :
    //
    {
        model.erase(object->GetName());
    } //----- Fin de Display

    //------------------------------------------------- Surcharge d'opérateurs
    /*AddPolygone & AddPolygone::operator = ( const AddPolygone & unAddPolygone )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


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
        istringstream iss(data);
        string name;
        vector<int> coord;
        iss >> name;
        do
        {
            int xy;
            iss >> xy;
            coord.push_back(xy);
        } while (iss);
        object = new Polygone(name, coord);
    } //----- Fin de AddPolygone


    AddPolygone::~AddPolygone ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddPolygone>" << endl;
    #endif
        delete object;
    } //----- Fin de ~AddPolygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
