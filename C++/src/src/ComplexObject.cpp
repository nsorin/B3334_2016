
    /*************************************************************************
                               ComplexObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <ComplexObject> (fichier ComplexObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/ComplexObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    std::vector<Object*> ComplexObject::GetTabObjects() const
    {
        return this->tabObjects;
    }

    void ComplexObject::AddObject(Object *object)
    {
        this->tabObjects.push_back(object->clone());
    }

    void ComplexObject::Move(int dx, int dy)
    {
        for(unsigned int i=0; i<tabObjects.size(); i++)
        {
            tabObjects[i]->Move(dx, dy);
        }
    }

    bool ComplexObject::Contains(Point & point) const
    {
        return true;
    }

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    ComplexObject::ComplexObject ( string n ) : Object(n)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <ComplexObject>" << endl;
    #endif
    } //----- Fin de ComplexObject


    ComplexObject::~ComplexObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <ComplexObject>" << endl;
    #endif
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            delete tabObjects[i];
        }
        tabObjects.clear();
    } //----- Fin de ~ComplexObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & ComplexObject::doPrint(ostream & os) const
    {
        os << "undefined complex object";
        return os;
    }

    Object * ComplexObject::clone()
    {
        ComplexObject* o = new ComplexObject(name);
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            o->AddObject(tabObjects[i]);
        }
        return o;
    }
