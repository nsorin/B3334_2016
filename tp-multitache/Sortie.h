/*************************************************************************
                           SORTIE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Interface de la tâche <SORTIE> (fichier SORTIE.h) -------
#if ! defined ( SORTIE_H )
#define SORTIE_H

//------------------------------------------------------------------------
// Rôle de la tâche <SORTIE>
// Tâche gérant les sorties des voitures à la porte de Sortie.
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Heure.h"
#include "Outils.h"
#include "Menu.h"
#include "Donnees.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void Sortie ( TypeBarriere type, int semEtatId, int memEtatId,
			int semRequeteId, int memRequeteId, int semEntreeSortieId,
			const char* nomCanalSortie );

#endif // SORTIE_H
