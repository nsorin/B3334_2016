/*************************************************************************
                           ENTREE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Interface de la tâche <ENTREE> (fichier ENTREE.h) -------
#if ! defined ( ENTREE_H )
#define ENTREE_H

//------------------------------------------------------------------------
// Rôle de la tâche <ENTREE>
// Tâche gérant l'arrivée des voitures aux portes d'entrée
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include "Heure.h"
#include "Outils.h"
#include "Menu.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Entree(TypeBarriere type, int semEtatId, int memEtatId, int semRequeteId,
  int memRequeteId, int semEntreeSortieId, short unsigned int semEntreeSortieNum,
  const char* nomCanalSortie);

#endif // ENTREE_H
