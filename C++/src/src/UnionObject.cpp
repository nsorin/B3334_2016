
    /*************************************************************************
                               UnionObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <UnionObject> (fichier UnionObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/UnionObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool UnionObject::Contains ( Point & p ) const
    {
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            if(tabObjects[i]->Contains(p))
            {
                return true;
            }
        }
        return false;
    } //----- Fin de Contains


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    UnionObject::UnionObject (string n) : ComplexObject(n)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <UnionObject>" << endl;
    #endif
    } //----- Fin de UnionObject


    UnionObject::~UnionObject ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <UnionObject>" << endl;
    #endif
    } //----- Fin de ~UnionObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & UnionObject::doPrint(ostream & os) const
    {
        os << "OR ";
        os << name << endl << "{" << endl;
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            tabObjects[i]->doPrint(os);
        }
        os << "}" << endl;
        return os;
    }

    Object * UnionObject::clone()
    {
        ComplexObject* o = new UnionObject(name);
        for(unsigned int i = 0; i<tabObjects.size(); i++)
        {
            o->AddObject(tabObjects[i]);
        }
        return o;
    }
