
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
    void UnionObject::Display() const
    {

    }

    //------------------------------------------------- Surcharge d'opérateurs
    /*UnionObject & UnionObject::operator = ( const UnionObject & unUnionObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    UnionObject::UnionObject ( const UnionObject & unUnionObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <UnionObject>" << endl;
    #endif
    } //----- Fin de UnionObject (constructeur de copie)


    UnionObject::UnionObject (string name)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <UnionObject>" << endl;
    #endif
        this->name = name;
    } //----- Fin de UnionObject


    UnionObject::~UnionObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <UnionObject>" << endl;
    #endif
    } //----- Fin de ~UnionObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
