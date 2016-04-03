/*************************************************************************
                           XXX  -  description
                             -------------------
    début                : XXX
    copyright            : (C) XXX par XXX
    e-mail               : XXX
*************************************************************************/

//---------- Interface de la tâche <XXX> (fichier XXX.h) -------
#if ! defined ( MERE_H )
#define MERE_H

//------------------------------------------------------------------------
// Rôle de la tâche <XXX>
//
//
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
// type Nom ( liste de paramètres );
// Mode d'emploi :
//
// Contrat :
//

bool InitPass();
void DelPass();

#endif // MERE_H
