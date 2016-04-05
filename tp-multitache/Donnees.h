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

//------------------------------------------------------------------ Types
typedef struct
{
	TypeUsager type;
	unsigned int num;
} Voiture;

typedef struct
{
	Voiture voiture;
	unsigned int arrivee;
} EtatPlace;

typedef struct
{
	EtatPlace places[NB_PLACES];
} StructMemEtat;

typedef struct
{
	TypeBarriere barriere;
	Voiture voiture;
	unsigned int arrivee;
} RequetePlace;

typedef struct
{
	RequetePlace requetes[NB_BARRIERES_ENTREE];
} StructMemRequete;

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

#endif // DONNEES_H
