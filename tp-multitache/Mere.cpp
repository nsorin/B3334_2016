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
#include "Mere.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
/* Processus */
static pid_t noHeure;
static pid_t noSimu;
static pid_t noSortie;
static pid_t noEntreeGB;
static pid_t noEntreeBPP;
static pid_t noEntreeBPA;
/* Semaphore */
static int semEcranId;
static int semEtatId;
static int semRequeteId;
static int semEntreeSortieId;
/* Mémoire partagée */
static int memEtatId;
static int memRequeteId;
//------------------------------------------------------ Fonctions privées
int main()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	InitApp();
	InitialiserApplication(VT220);
	noHeure = ActiverHeure();
	/*if((noSortie = fork()) == 0)
	{
		Sortie();
	}
	else if((noEntreeGB = fork()) == 0)
	{
		Entree();
	}
	else if((noEntreeBPP = fork()) == 0)
	{
		Entree();
	}
	else if((noEntreeBPA = fork()) == 0)
	{
		Entree();
	}*/
	//waitpid(noSimu, NULL, 0);
	/*
	kill(noSortie, SIGUSR2);
	kill(noEntreeGB, SIGUSR2);
	kill(noEntreeBPP, SIGUSR2);
	kill(noEntreeBPA, SIGUSR2);
	waitpid(noSortie, NULL, 0);
	waitpid(noEntreeGB, NULL, 0);
	waitpid(noEntreeBPP, NULL, 0);
	waitpid(noEntreeBPA, NULL, 0);
	*/
	sleep(10); // TEMPORAIRE
	kill(noHeure, SIGUSR2);
	TerminerApplication(true);
	TermApp();

	return 0;
} //----- fin de main

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void InitApp (  )
// Algorithme :
//
{
	// Créé les processus
	// Créé les sémaphores
	semEcranId = semget(IPC_PRIVATE, 1, IPC_CREAT);
	semEtatId = semget(IPC_PRIVATE, 1, IPC_CREAT);
	semRequeteId = semget(IPC_PRIVATE, 1, IPC_CREAT);
	semEntreeSortieId = semget(IPC_PRIVATE, 3, IPC_CREAT);
	// Créé la mémoire partagée
	memEtatId = shmget(IPC_PRIVATE, sizeof(EtatPlace), IPC_CREAT);
	memRequeteId = shmget(IPC_PRIVATE, sizeof(RequetePlace), IPC_CREAT);

} //----- fin de InitApp

void TermApp (  )
// Algorithme :
//
{
	// Supprime la mémoire partagée
	shmctl(memEtatId, IPC_RMID, 0);
	shmctl(memRequeteId, IPC_RMID, 0);
	// Supprime les sémaphores
	semctl(semEcranId, 1, IPC_RMID, 0);
	semctl(semEtatId, 1, IPC_RMID, 0);
	semctl(semRequeteId, 1, IPC_RMID, 0);
	semctl(semEntreeSortieId, 3, IPC_RMID, 0);

} //----- fin de TermApp
