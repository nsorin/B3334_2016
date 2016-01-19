
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
    std::vector<Object> ComplexObject::GetTabObjects() const
    {
        return this->tabObjects;
    }

    void ComplexObject::AddObject(Object object)
    {
        this->tabObjects.push_back(object);
    }

    void ComplexObject::Move(int dx, int dy)
    {
        
    }

    bool ComplexObject::Contains(Point * point) const
    {
        return true;
    }

    //------------------------------------------------- Surcharge d'opérateurs
    /*ComplexObject & ComplexObject::operator = ( const ComplexObject & unComplexObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    ComplexObject::ComplexObject ( const ComplexObject & unComplexObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <ComplexObject>" << endl;
    #endif
    } //----- Fin de ComplexObject (constructeur de copie)


    ComplexObject::ComplexObject ( )
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
    } //----- Fin de ~ComplexObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
