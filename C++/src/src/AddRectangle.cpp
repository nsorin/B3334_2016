
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

    bool AddRectangle::Do ( map<string, Object> & model )
    // Algorithme :
    //
    {
        if ( model.find(object->GetName()) == model.end() )
        {
            model[object->GetName()] = *object;
            return true;
        }
        else
        {
            return false;
        }
    } //----- Fin de Do

    bool AddRectangle::Undo ( map<string, Object> & model )
    // Algorithme :
    //
    {
        model.erase(object->GetName());
        return true;
    } //----- Fin de Undo

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


    AddRectangle::AddRectangle ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddRectangle>" << endl;
    #endif
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
        delete object;
    } //----- Fin de ~AddRectangle


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
