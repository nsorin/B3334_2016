
    /*************************************************************************
                               AddSegment  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <AddSegment> (fichier AddSegment) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/AddSegment.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    void AddSegment::Display ( )
    // Algorithme :
    //
    {
    } //----- Fin de Display

    bool AddSegment::Do ( map<string, Object*> & model )
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

    bool AddSegment::Undo ( map<string, Object*> & model )
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
    AddSegment::AddSegment ( string & data )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddSegment>" << endl;
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
        object = new Segment(name, x1, y1, x2, y2);
    } //----- Fin de AddSegment


    AddSegment::~AddSegment ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddSegment>" << endl;
    #endif
        if(undone)
        {
            delete object;
        }
    } //----- Fin de ~AddSegment


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
