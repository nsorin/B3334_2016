
    /*************************************************************************
                               Object  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Object> (fichier Object) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Object.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool Object::Contains ( Point & p ) const
    {
        return false;
    } //----- Fin de Contains

    string Object::GetName ( ) const
    {
        return name;
    } //----- Fin de GetName

    void Object::Move ( int dx, int dy )
    {

    } //----- Fin de GetName

    //------------------------------------------------- Surcharge d'opérateurs

    ostream & operator<< (ostream & stream, Object & object)
    {
        return object.doPrint(stream);
    }

    //-------------------------------------------- Constructeurs - destructeur
    Object::Object ( const Object & unObject )
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Object>" << endl;
    #endif
    } //----- Fin de Object (constructeur de copie)


    Object::Object ( string n ) : name(n)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Object>" << endl;
    #endif
    } //----- Fin de Object


    Object::~Object ( )
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Object>" << endl;
    #endif
    } //----- Fin de ~Object


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & Object::doPrint(ostream & os) const
    {
        os << "undefined object " << name << endl;
        return os;
    }

    Object * Object::clone()
    {
        Object* o = new Object(name);
        return o;
    }
