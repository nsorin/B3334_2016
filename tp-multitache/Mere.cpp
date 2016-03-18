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
#include <unistd.h>


//------------------------------------------------------ Include personnel
#include "Mere.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static pid_t pid_heure;
static int sem_id;
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
	/*while(true)
	{

	}*/
	sleep(3);
	TermApp();

	return 0;
} //----- fin de main

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
void InitApp (  )
// Algorithme :
//
{
	pid_heure = ActiverHeure();
	sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT);

} //----- fin de InitApp

void TermApp (  )
// Algorithme :
//
{
	semctl(sem_id, 1, IPC_RMID, 0);
	kill(pid_heure, SIGUSR2);
} //----- fin de TermApp
