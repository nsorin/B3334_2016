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
#include <dos.h>


//------------------------------------------------------ Include personnel
#include "Mere.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static pid_t pid_heure;
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
} //----- fin de InitApp

void TermApp (  )
// Algorithme :
//
{
	kill(pid_heure, SIGUSR2);
} //----- fin de TermApp
