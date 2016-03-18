/*************************************************************************
                           XXX  -  description
                             -------------------
    début                : XXX
    copyright            : (C) XXX par XXX
    e-mail               : XXX
*************************************************************************/

//---------- Réalisation de la tâche <XXX> (fichier XXX.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <unistd.h>

//------------------------------------------------------ Include personnel
#include "Sortie.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void initialisation (  )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
} //----- fin de initialisation

static void moteur (  )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
} //----- fin de moteur

static void destruction (  )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Sortie ( TypeBarriere type, int semEtatId, int memEtatId, 
			int semRequeteId, int memRequeteId, int semEntreeSortieId, 
			int semEcranId )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	initialisation();
	for(;;)
	{
		moteur();
	}
}
