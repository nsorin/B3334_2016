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
#include <map>

//------------------------------------------------------ Include personnel
#include "Sortie.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static TypeBarriere barriere;
static int semEtatId;
static int memEtatId;
static int semRequeteId;
static int memRequeteId;
static int semEntreeSortieId;
static int descCanalSortie;
static const char* nomCanalSimu;
static map<pid_t,Voiture> voituriersEnService;
//------------------------------------------------------ Fonctions privées
static void initialisation ( TypeBarriere type, int semEtatIdExt, int memEtatIdExt,
			int semRequeteIdExt, int memRequeteIdExt, int semEntreeSortieIdExt, const char* nomCanalSortie )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	// Initialisation des variables static
	barriere = type;
	semEtatId = semEtatIdExt;
	memEtatId = memEtatIdExt;
	semRequeteId = semRequeteIdExt;
	memRequeteId = memRequeteIdExt;
	semEntreeSortieId = semEntreeSortieIdExt;
	nomCanalSimu = nomCanalSortie;

	// Handler de destruction
	struct sigaction actionDestruction;
	actionDestruction.sa_handler = destruction;
	sigemptyset(&actionDestruction.sa_mask);
	actionDestruction.sa_flags = 0;
	sigaction(SIGUSR2, &actionDestruction, NULL);

	// Handler de mort d'un voiturier
	struct sigaction actionMortVoiturier;
	actionMortVoiturier.sa_handler = mortVoiturier;
	sigemptyset(&actionMortVoiturier.sa_mask);
	actionMortVoiturier.sa_flags = 0;
	sigaction(SIGCHLD, &actionMortVoiturier, NULL);

	// Ouverture du canal de communication avec Simu
	nomCanalSimu = nomCanalSortie;


} //----- fin de initialisation

static void handlerMortVoiturier ( int numSignal )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	if(numSignal == SIGCHLD)
	{
		
	}
} //----- fin de moteur

static void moteur (  )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	int numPlaceVoiture;

	// On récupère le numéro de la place dans le canal relié à la simu
	if(read(descCanalSimu, &numPlaceVoiture, sizeof(int) > 0))
	{
		// On ajoute un voiturier dans la liste
		voituriersEnService.push_back(SortirVoiture(numPlaceVoiture));
	}
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
		
		// Destruction des voituriers en service
		for(vector<pid_t>::iterator i = voituriersEnService.begin(); i != voituriersEnService.end(); i++){
			kill(*i, SIGUSR2);
		}
		// Attente de confirmation
		for(vector<pid_t>::iterator i = voituriersEnService.begin(); i != voituriersEnService.end(); i++){
			waitpid(*i,NULL,0);
		}

		// Suicide de la tâche
		exit(0);
	}
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Sortie ( TypeBarriere type, int semEtatIdExt, int memEtatIdExt,
			int semRequeteIdExt, int memRequeteIdExt, int semEntreeSortieIdExt, const char* nomCanalSortie )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	initialisation(type, semEtatIdExt, memEtatIdExt,
			semRequeteIdExt, memRequeteIdExt, semEntreeSortieIdExt, nomCanalSortie);
	for(;;)
	{
		moteur();
	}
}
