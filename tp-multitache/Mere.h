/*************************************************************************
                           MERE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Interface de la tâche <MERE> (fichier MERE.h) -------
#if ! defined ( MERE_H )
#define MERE_H

//------------------------------------------------------------------------
// Rôle de la tâche <MERE>
// Tâche mère de l'application, initialisant et détruisant tous les objets
// et tâches utilisés par l'application.
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Heure.h"
#include "Outils.h"
#include "Menu.h"

//------------------------------------------------------------- Constantes
const char* NOM_CANAL_BPP = "canalBPP";
const char* NOM_CANAL_BPA = "canalBPA";
const char* NOM_CANAL_GB = "canalGB";
const char* NOM_CANAL_SORTIE = "canalSortie";

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

bool InitPass();
void DelPass();

#endif // MERE_H
