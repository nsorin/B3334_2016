#!/usr/local/bin/python
# -*- coding: utf-8 -*-

import datetime

date = datetime.datetime.now()
day = str(date.day)+"/"+str(date.month)+"/"+str(date.year)
year = str(date.year)
username = raw_input("Enter your username : ")
nbMod = input("Enter the number of classes you want to create : ")
tabClasses = []
for i in range(int(nbMod)):
    name = raw_input("Enter the name of the class {0} : ".format(i+1))
    tabClasses.append(name)
for aClass in tabClasses:
    fh = open(aClass+".h", "a")
    strH = """
    /*************************************************************************
                               {0}  -  description
                                 -------------------
        début                : {2}
        copyright            : (C) {3} par {1}
    *************************************************************************/

    //-------------- Interface de la classe <{0}> (fichier {0}) --------------
    #if ! defined ( {4} )
    #define {4}

    //--------------------------------------------------- Interfaces utilisées

    //------------------------------------------------------------- Constantes

    //------------------------------------------------------------------ Types

    //------------------------------------------------------------------------
    // Rôle de la classe <{0}>
    //
    //
    //------------------------------------------------------------------------

    class {0}
    {{
    //----------------------------------------------------------------- PUBLIC

    public:
    //----------------------------------------------------- Méthodes publiques
        // type Méthode ( liste de paramètres );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //------------------------------------------------- Surcharge d'opérateurs
        {0} & operator = ( const {0} & un{0} );
        // Mode d'emploi :
        //
        // Contrat :
        //


    //-------------------------------------------- Constructeurs - destructeur
        {0} ( const {0} & un{0} );
        // Mode d'emploi (constructeur de copie) :
        //
        // Contrat :
        //

        {0} ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

        virtual ~{0} ( );
        // Mode d'emploi :
        //
        // Contrat :
        //

    //------------------------------------------------------------------ PRIVE

    protected:
    //----------------------------------------------------- Méthodes protégées

    private:
    //------------------------------------------------------- Méthodes privées

    protected:
    //----------------------------------------------------- Attributs protégés

    private:
    //------------------------------------------------------- Attributs privés

    //---------------------------------------------------------- Classes amies

    //-------------------------------------------------------- Classes privées

    //----------------------------------------------------------- Types privés

    }};

    //----------------------------------------- Types dépendants de <{0}>

    #endif // {4}
    """.format(aClass, username, day, year, aClass.upper()+"_H")
    fh.write(strH)
    fh.close()
    fcpp = open(aClass+".cpp", "a")
    strCPP = """
    /*************************************************************************
                               {0}  -  description
                                 -------------------
        début                : {2}
        copyright            : (C) {3} par {1}
    *************************************************************************/

    //---------- Réalisation de la classe <{0}> (fichier {0}) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "{0}.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    // type {0}::Méthode ( liste de paramètres )
    // Algorithme :
    //
    //{{
    //}} //----- Fin de Méthode


    //------------------------------------------------- Surcharge d'opérateurs
    {0} & {0}::operator = ( const {0} & un{0} )
    // Algorithme :
    //
    {{
    }} //----- Fin de operator =


    //-------------------------------------------- Constructeurs - destructeur
    {0}::{0} ( const {0} & un{0} )
    // Algorithme :
    //
    {{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <{0}>" << endl;
    #endif
    }} //----- Fin de {0} (constructeur de copie)


    {0}::{0} ( )
    // Algorithme :
    //
    {{
    #ifdef MAP
        cout << "Appel au constructeur de <{0}>" << endl;
    #endif
    }} //----- Fin de {0}


    {0}::~{0} ( )
    // Algorithme :
    //
    {{
    #ifdef MAP
        cout << "Appel au destructeur de <{0}>" << endl;
    #endif
    }} //----- Fin de ~{0}


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    """.format(aClass, username, day, year)
    fcpp.write(strCPP)
    fcpp.close()
    print("{0}.h et {0}.cpp ont été créées.".format(aClass))
