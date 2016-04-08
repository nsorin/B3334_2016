/*************************************************************************
                           SIMU  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Interface de la tâche <SIMU> (fichier SIMU.h) -------
#if ! defined ( SIMU_H )
#define SIMU_H

//------------------------------------------------------------------------
// Rôle de la tâche <SIMU>
// Tâche gérant les entrées clavier et l'affichage du menu
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Simu(const char* nomCanalBPP, const char* nomCanalBPA,
  const char* nomCanalGB, const char* nomCanalSortie);

void Commande(char code, unsigned int valeur);

#endif // SIMU_H
