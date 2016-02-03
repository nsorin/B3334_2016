
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
    void AddRectangle::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool AddRectangle::Do ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        undone = false;
        if ( model.find(object->GetName()) == model.end() )
        {
            model[object->GetName()] = object;
            cout << "OK" << endl;
            return true;
        }
        else
        {
            cout << "ERR" << endl;
            delete object;
            return false;
        }
    } //----- Fin de Do

    bool AddRectangle::Undo ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        undone = true;
        model.erase(object->GetName());
        cout << "OK" << endl;
        return true;
    } //----- Fin de Undo

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    AddRectangle::AddRectangle ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddRectangle>" << endl;
    #endif
        undone = false;
        string name;
        int x1;
        int x2;
        int y1;
        int y2;
        istringstream iss(data);
        iss >> name;
        iss >> x1;
        iss >> y1;
        iss >> x2;
        iss >> y2;
        object = new Rectangle(name, x1, y1, x2, y2);

    } //----- Fin de AddRectangle


    AddRectangle::~AddRectangle ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddRectangle>" << endl;
    #endif
        if(undone)
        {
            delete object;
        }
    } //----- Fin de ~AddRectangle


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
