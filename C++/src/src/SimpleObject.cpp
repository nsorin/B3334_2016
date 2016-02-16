
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
    {
        return false;
    } //----- Fin de Contains

    void SimpleObject::Move( int dx, int dy )
    {
        for(unsigned int i=0; i<nPoints; i++)
        {
            tabPoints[i].Move(dx, dy);
        }
    } //----- Fin de Move

    Point* SimpleObject::GetTabPoints( ) const
    {
      return tabPoints;
    } //----- Fin de GetTabPoints

    unsigned int SimpleObject::GetSize( ) const
    {
        return nPoints;
    } //----- Fin de GetSize


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    SimpleObject::SimpleObject ( string n, unsigned int np ) : Object(n), nPoints(np)
    {
    #ifdef MAP
        cout << "Appel au constructeur de <SimpleObject>" << endl;
    #endif
        tabPoints = new Point[nPoints];
    } //----- Fin de SimpleObject


    SimpleObject::~SimpleObject ( )
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
