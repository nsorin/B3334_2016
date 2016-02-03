
    /*************************************************************************
                               SimpleObject  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <SimpleObject> (fichier SimpleObject) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/SimpleObject.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool SimpleObject::Contains ( Point & p ) const
    // Algorithme :
    //
    {
        return false;
    } //----- Fin de Contains

    void SimpleObject::Move( int dx, int dy )
    // Algorithme :
    //
    {
        for(unsigned int i=0; i<nPoints; i++)
        {
            tabPoints[i].Move(dx, dy);
        }
    } //----- Fin de Move

    Point* SimpleObject::GetTabPoints( ) const
    // Algorithme :
    //
    {
      return tabPoints;
    } //----- Fin de GetTabPoints

    unsigned int SimpleObject::GetSize( ) const
    // Algorithme :
    //
    {
        return nPoints;
    } //----- Fin de GetSize


    //------------------------------------------------- Surcharge d'opérateurs
    /*SimpleObject & SimpleObject::operator = ( const SimpleObject & unSimpleObject )
    // Algorithme :
    //
    {
    } //----- Fin de operator =*/


    //-------------------------------------------- Constructeurs - destructeur
    SimpleObject::SimpleObject ( const SimpleObject & unSimpleObject )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de copie de <SimpleObject>" << endl;
    #endif
    } //----- Fin de SimpleObject (constructeur de copie)


    SimpleObject::SimpleObject ( string n, unsigned int np ) : Object(n), nPoints(np)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <SimpleObject>" << endl;
    #endif
        tabPoints = new Point[nPoints];
    } //----- Fin de SimpleObject


    SimpleObject::~SimpleObject ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <SimpleObject>" << endl;
    #endif
        delete[] tabPoints;
    } //----- Fin de ~SimpleObject


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    ostream & SimpleObject::doPrint(ostream & os) const
    {
        os << "undefined simple object " << name;
        return os;
    }

    Object * SimpleObject::clone()
    {
        Object* o = new SimpleObject(name, nPoints);
        return o;
    }
