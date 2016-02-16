/*************************************************************************
                            ComplexObject  -  description
                                -------------------
    début                : 16/1/2016
    copyright            : (C) 2016 par nsorin
*************************************************************************/

//-------------- Interface de la classe <ComplexObject> (fichier ComplexObject) --------------
#if ! defined ( COMPLEXOBJECT_H )
#define COMPLEXOBJECT_H

//--------------------------------------------------- Interfaces utilisées
#include "Object.h"
#include "Point.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <ComplexObject>
// Classe abstraite caractérisant un objet complexe issus d'une opération
// entre des objets simples ou complexes
//------------------------------------------------------------------------

class ComplexObject : public Object
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::vector<Object*> GetTabObjects() const;

    void AddObject(Object * o);

    void ClearObjects();

    void Move(int dx, int dy);

    virtual bool Contains(Point & p) const;

    virtual std::ostream & doPrint(std::ostream & os) const;

    virtual Object * clone();

//------------------------------------------------- Surcharge d'opérateurs
    friend std::ostream & operator<< (std::ostream & stream, const ComplexObject & object);


//-------------------------------------------- Constructeurs - destructeur
    ComplexObject ( std::string n = "" );

    virtual ~ComplexObject ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
    std::vector<Object*> tabObjects; //Vector d'objets simples ou complexes constituant l'objet courant

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <ComplexObject>

#endif // COMPLEXOBJECT_H
