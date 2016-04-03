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
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Simu(const char* nomCanalBPP, const char* nomCanalBPA, const char* nomCanalGB, const char* nomCanalSortie);
// Mode d'emploi :
//
// Contrat :
//

void Commande(char code, unsigned int valeur);
// Mode d'emploi :
//
// Contrat :
//

#endif // SIMU_H
