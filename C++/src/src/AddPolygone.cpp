
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
    bool AddPolygone::Do ( map<string, Object*> & model )
    {
        undone = false;
        if ( model.find(object->GetName()) == model.end() && !invalid )
        {
            if(object->IsConvex())
            {
                model[object->GetName()] = object;
                return true;
            }
            else
            {
                delete object;
                return false;
            }
        }
        else
        {
            delete object;
            return false;
        }
    } //----- Fin de Display

    bool AddPolygone::Undo ( map<string, Object*> & model )
    {
        undone = true;
        model.erase(object->GetName());
        return true;
    } //----- Fin de Display

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    AddPolygone::AddPolygone ( std::string & data ) //: undone(false)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <AddPolygone>" << endl;
    #endif
        undone = false;
        invalid = false;
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
        coord.pop_back();
        invalid = (coord.size() < 6 || coord.size() % 2 == 1);
        vector<Point> points;
        for(unsigned int i=0; i<coord.size(); i+=2)
        {
            Point p(coord[i], coord[i+1]);
            points.push_back(p);
        }
        object = new Polygone(name, points);
    } //----- Fin de AddPolygone


    AddPolygone::~AddPolygone ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <AddPolygone>" << endl;
    #endif
        if(undone)
        {
            delete object;
        }
    } //----- Fin de ~AddPolygone


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
