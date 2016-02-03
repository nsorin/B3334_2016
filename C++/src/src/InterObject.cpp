
    /*************************************************************************
                               InterObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <InterObject> (fichier InterObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/InterObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool InterObject::Contains ( Point & p ) const
    // Algorithme :
    //
    {
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            if(!tabObjects[i]->Contains(p))
            {
                return false;
            }
        }
        return true;
    } //----- Fin de Contains

    void InterObject::Display() const
    {

    }

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    InterObject::InterObject (string n) : ComplexObject(n)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <InterObject>" << endl;
    #endif
    } //----- Fin de InterObject


    InterObject::~InterObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <InterObject>" << endl;
    #endif
    } //----- Fin de ~InterObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & InterObject::doPrint(ostream & os) const
    {
        os << "OI ";
        os << name << " " << "(" << tabObjects.size() << ")" << " " << endl;
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            os << "    --> ";
            tabObjects[i]->doPrint(os);
        }
        return os;
    }

    Object * InterObject::clone()
    {
        ComplexObject* o = new InterObject(name);
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            o->AddObject(tabObjects[i]);
        }
        return o;
    }
