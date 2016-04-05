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
#include <fcntl.h>

//------------------------------------------------------ Include personnel
#include "Sortie.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static int descCanalSortie;
//------------------------------------------------------ Fonctions privées
static void initialisation ( const char* nomCanalSortie )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	descCanalSortie = open(nomCanalSortie, O_RDONLY);
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

static void destruction ( int noSignal )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	if( noSignal == SIGUSR2 )
	{
		// Fermeture du canal de communication
		close(descCanalSortie);
		// Suicide de la tâche
		exit(0);
	}
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Sortie ( TypeBarriere type, int semEtatId, int memEtatId,
			int semRequeteId, int memRequeteId, int semEntreeSortieId, const char* nomCanalSortie )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	initialisation(nomCanalSortie);
	for(;;)
	{
		moteur();
	}
}
