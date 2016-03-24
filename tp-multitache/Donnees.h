/*************************************************************************
                           DONNEES  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Interface de la tâche <DONNEES> (fichier DONNEES.h) -------
#if ! defined ( DONNEES_H )
#define DONNEES_H

//------------------------------------------------------------------------
// Rôle de la tâche <DONNEES>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Outils.h"
//------------------------------------------------------------- Constantes
const TypeTerminal TERM_TYPE = VT220;

const char* NOM_CANAL_BPP = "canalBPP";
const char* NOM_CANAL_BPA = "canalBPA";
const char* NOM_CANAL_GB = "canalGB";
const char* NOM_CANAL_SORTIE = "canalSortie";

//------------------------------------------------------------------ Types
typedef struct
{
	TypeUsager type;
	int num;
	int arrivee;
} EtatPlace;

typedef struct
{
	TypeBarriere barriere;
	TypeUsager usager;
	int arrivee;
} RequetePlace;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

#endif // DONNEES_H
