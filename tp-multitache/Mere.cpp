/*************************************************************************
                           XXX  -  description
                             -------------------
    debut                : XXX
    copyright            : (C) XXX par XXX
    e-mail               : XXX
*************************************************************************/

//---------- Realisation de la tâche <XXX> (fichier XXX.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Mere.h"
#include "Donnees.h"
#include "Entree.h"
#include "Sortie.h"
#include "Simu.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes
/* Droits */
#define DROITS 0666
//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
/* Processus */
static pid_t noHeure = -1;
static pid_t noSimu = -1;
static pid_t noSortie = -1;
static pid_t noEntreeGB = -1;
static pid_t noEntreeBPP = -1;
static pid_t noEntreeBPA = -1;
/* Semaphore */
static int semEcranId = -1;
static int semEtatId = -1;
static int semRequeteId = -1;
static int semEntreeSortieId = -1;
/* Memoire partagee */
static int memEtatId = -1;
static int memRequeteId = -1;
//------------------------------------------------------ Fonctions privees
int main()
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	if(!InitPass())
	{
		cerr << "Erreur à l'initialisation des objets passifs\n";
		DelPass();
		return -1;
	}
	InitialiserApplication(VT220);
	noHeure = ActiverHeure();

	if((noSimu = fork()) == 0)
	{
		Simu(NOM_CANAL_BPP, NOM_CANAL_BPA, NOM_CANAL_GB, NOM_CANAL_SORTIE);
	}
	else if((noSortie = fork()) == 0)
	{
		Sortie(SORTIE_GASTON_BERGER, semEtatId, memEtatId, semRequeteId, memRequeteId, semEntreeSortieId, NOM_CANAL_SORTIE);
	}
	else if((noEntreeGB = fork()) == 0)
	{
		Entree(ENTREE_GASTON_BERGER, semEtatId, memEtatId, semRequeteId, memRequeteId, semEntreeSortieId, 2, NOM_CANAL_GB);
	}
	else if((noEntreeBPP = fork()) == 0)
	{
		Entree(PROF_BLAISE_PASCAL, semEtatId, memEtatId, semRequeteId, memRequeteId, semEntreeSortieId, 0, NOM_CANAL_BPP);
	}
	else if((noEntreeBPA = fork()) == 0)
	{
		Entree(AUTRE_BLAISE_PASCAL, semEtatId, memEtatId, semRequeteId, memRequeteId, semEntreeSortieId, 1, NOM_CANAL_BPA);
	}
	else
	{
		// Attente de la fin de la simulation
		waitpid(noSimu, NULL, 0);

		// Arrêt des processus fils
		kill(noSortie, SIGUSR2);
		waitpid(noSortie, NULL, 0);
		kill(noEntreeGB, SIGUSR2);
		waitpid(noEntreeGB, NULL, 0);
		kill(noEntreeBPP, SIGUSR2);
		waitpid(noEntreeBPP, NULL, 0);
		kill(noEntreeBPA, SIGUSR2);
		waitpid(noEntreeBPA, NULL, 0);
		kill(noHeure, SIGUSR2);
		waitpid(noHeure, NULL, 0);

		// Suppression des objets passifs
		DelPass();
		TerminerApplication(true);
		exit(0);
	}

	return 0;
} //----- fin de main

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
bool InitPass (  )
// Algorithme :
// Cette fonction initialise tous les objets passifs de l'application
{
	// Cree les semaphores
	semEcranId = semget(IPC_PRIVATE, 1, IPC_CREAT | DROITS);
	semEtatId = semget(IPC_PRIVATE, 1, IPC_CREAT | DROITS);
	semRequeteId = semget(IPC_PRIVATE, 1, IPC_CREAT | DROITS);
	semEntreeSortieId = semget(IPC_PRIVATE, 3, IPC_CREAT | DROITS);
	if(semEcranId == -1 || semEtatId == -1 || semRequeteId == -1 || semEntreeSortieId == -1)
	{
		return false;
	}
	semctl(semEcranId, 0, SETVAL, 0);
	semctl(semEtatId, 0, SETVAL, 0);
	semctl(semRequeteId, 0, SETVAL, 0);
	semctl(semEntreeSortieId, 0, SETVAL, 1);
	semctl(semEntreeSortieId, 1, SETVAL, 1);
	semctl(semEntreeSortieId, 2, SETVAL, 1);

	// Cree la memoire partagee
	memEtatId = shmget(IPC_PRIVATE, sizeof(StructMemEtat), IPC_CREAT | DROITS);
	memRequeteId = shmget(IPC_PRIVATE, sizeof(StructMemRequete), IPC_CREAT | DROITS);
	if(memEtatId == -1 || memRequeteId == -1)
	{
		return false;
	}
	// Initialisation des requêtes vides
	// Attachement à la mémoire partagée des requêtes
	StructMemRequete* memReq = (StructMemRequete*) shmat(memRequeteId,NULL,0);
	for(unsigned int i=0; i<NB_BARRIERES_ENTREE; i++)
	{
      	// Ajout de la requête
      	RequetePlace req;
      	Voiture voitureFausse;
      	voitureFausse.type = AUCUN;
      	req.voiture = voitureFausse;
      	req.arrivee = 0;
      	memReq->requetes[i] = req;
	}
	// Détachement de la mémoire partagée des requêtes
    shmdt(memReq);

	// Cree les canaux
	if(mkfifo(NOM_CANAL_BPP, DROITS) == -1)
	{
		return false;
	}
	if(mkfifo(NOM_CANAL_BPA, DROITS) == -1)
	{
		return false;
	}
	if(mkfifo(NOM_CANAL_GB, DROITS) == -1)
	{
		return false;
	}
	if(mkfifo(NOM_CANAL_SORTIE, DROITS) == -1)
	{
		return false;
	}
	return true;
} //----- fin de InitPass

void DelPass (  )
// Algorithme :
// Cette fonction supprime tous les objets passifs de l'application
{
	// Supprime les canaux
	unlink(NOM_CANAL_BPP);
	unlink(NOM_CANAL_BPA);
	unlink(NOM_CANAL_GB);
	unlink(NOM_CANAL_SORTIE);
	// Supprime la memoire partagee
	if(memEtatId != -1)
	{
		shmctl(memEtatId, IPC_RMID, 0);
	}
	if(memRequeteId != -1)
	{
		shmctl(memRequeteId, IPC_RMID, 0);
	}
	// Supprime les semaphores
	if(semEcranId != -1)
	{
		semctl(semEcranId, 1, IPC_RMID, 0);
	}
	if(semEtatId != -1)
	{
		semctl(semEtatId, 1, IPC_RMID, 0);
	}
	if(semRequeteId != -1)
	{
		semctl(semRequeteId, 1, IPC_RMID, 0);
	}
	if(semEntreeSortieId != -1)
	{
		semctl(semEntreeSortieId, 3, IPC_RMID, 0);
	}

} //----- fin de DelPass
