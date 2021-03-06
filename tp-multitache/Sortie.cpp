/*************************************************************************
                           SORTIE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Réalisation de la tâche <SORTIE> (fichier SORTIE.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <map>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

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
static int descCanalSimu;
static const char* nomCanalSimu;
static std::map<pid_t,unsigned int> voituriersEnService;
//------------------------------------------------------ Fonctions privées
static void destruction ( int numSignal );
static void mortVoiturier ( int numSignal );

static void initialisation ( TypeBarriere type, int semEtatIdExt,
	int memEtatIdExt, int semRequeteIdExt, int memRequeteIdExt,
	int semEntreeSortieIdExt, const char* nomCanalSortie )
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
	descCanalSimu = open(nomCanalSimu, O_RDONLY);



} //----- fin de initialisation

static void mortVoiturier ( int numSignal )
{
	// Création des divers sembuf
	struct sembuf reservation = {0, 1, 0};
	//struct sembuf attente = {0, 0, 0};
	struct sembuf liberation = {0, -1, 0};

	int status;
	// On récupère le pid du voiturier qui a envoyé SIGCHLD
	pid_t voiturier = wait(&status);
	// On efface la place correspondante
	Effacer((TypeZone)WEXITSTATUS(status));

	// On libère la place sur la mémoire
	// On réserve la mémoire via le sémaphore correspondant
	while(semop(semEtatId,&reservation,1)==-1 && errno==EINTR);
	// On attache la mémoire
	StructMemEtat *etatParking = (StructMemEtat *) shmat(memEtatId, NULL, 0);
	// On récupère l'état de la place libérée
	EtatPlace etat = (EtatPlace) etatParking->places[WEXITSTATUS(status)];
	// On décrémente le nombre de places prises et on retient le nombre
	// de places libres
	unsigned int placesLibres = NB_PLACES - (--etatParking->nbPlacesPrises);
	// On libère la mémoire
	shmdt(etatParking);
	semop(semEtatId, &liberation, 1);
	// On affiche la sortie
	AfficherSortie(etat.voiture.type, etat.voiture.num, etat.arrivee, time(NULL));
	// On efface le voiturier détruit
	voituriersEnService.erase(voiturier);

	if( placesLibres == 1 )
	{
		// Si le parking était plein, on sélectionne parmis les requêtes
		// laquelle est prioritaire
		// On réserve la mémoire via le sémaphore correspondant
		while(semop(semRequeteId,&reservation,1)==-1 && errno==EINTR);
		// On attache la mémoire
		StructMemRequete *memRequetes = (StructMemRequete *) shmat(memRequeteId,
			NULL, 0);
		// On détermine la voiture prioritaire
		unsigned int voiturePrioritaire = NB_BARRIERES_ENTREE;
		for(unsigned int k=0; k<NB_BARRIERES_ENTREE; k++)
		{
			if(memRequetes->requetes[k].voiture.type != AUCUN)
			{
				// S'il y a quelqu'un qui attend à cette barrière
				if(memRequetes->requetes[voiturePrioritaire].voiture.type == AUCUN)
				{
					// La requete k est prioritaire
					voiturePrioritaire = k;
				}
				else if( memRequetes->requetes[k].voiture.type == PROF )
				{
				// Si l'actuel prioritaire est un autre ou sil est arrivé après
					if( memRequetes->requetes[voiturePrioritaire].voiture.type == AUTRE
						|| memRequetes->requetes[voiturePrioritaire].arrivee >
						memRequetes->requetes[k].arrivee )
					{
						// La requete k est prioritaire
						voiturePrioritaire = k;
					}
				}
				else
				{
					// Si l'actuel prioritaire est un autre et qu'il est arrivé après
					if( memRequetes->requetes[voiturePrioritaire].voiture.type == AUTRE
						&& memRequetes->requetes[voiturePrioritaire].arrivee >
						memRequetes->requetes[k].arrivee )
					{
						// La requete k est prioritaire
						voiturePrioritaire = k;
					}
				}
			}

		}
		//On libère la mémoire
		shmdt(memRequetes);
		semop(semRequeteId, &liberation, 1);
		//On indique à l'entrée correspondante qu'elle peut faire entrer un usager,
		//sauf si personne n'attend
		if(voiturePrioritaire < NB_BARRIERES_ENTREE)
		{
			if(semctl(semEntreeSortieId, voiturePrioritaire, SETVAL, 0) == -1)
			{
				Afficher(MESSAGE,"Erreur de sémaphore EntreeSortie");
			}
		}
	}
} //----- fin de moteur

static void moteur (  )
{
	int numPlaceVoiture;

	// On récupère le numéro de la place dans le canal relié à la simu
	if(read(descCanalSimu, &numPlaceVoiture, sizeof(int)) > 0)
	{
		// On ajoute un voiturier dans la liste
		pid_t p = SortirVoiture(numPlaceVoiture);
		if( p != -1 )
		{
			voituriersEnService[p] = numPlaceVoiture;
		}
	}
} //----- fin de moteur

static void destruction ( int numSignal )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
{
	if( numSignal == SIGUSR2 )
	{
		// Fermeture du canal de communication
		close(descCanalSimu);

		// On annule l'impact des signaux SIGCHLD au cas ou un
		// voiturier mourrait dans l'intervalle de temps
		struct sigaction actionChild;
		actionChild.sa_handler = SIG_IGN;
		sigemptyset(&actionChild.sa_mask);
		actionChild.sa_flags = 0;
		sigaction(SIGCHLD, &actionChild, NULL);

		// Destruction des voituriers en service
		for(std::map<pid_t, unsigned int>::iterator i = voituriersEnService.begin();
		 i != voituriersEnService.end(); i++){
			kill(i->first, SIGUSR2);
		}
		// Attente de confirmation
		for(std::map<pid_t, unsigned int>::iterator i = voituriersEnService.begin();
		 i != voituriersEnService.end(); i++){
			waitpid(i->first,NULL,0);
		}

		// Suicide de la tâche
		exit(0);
	}
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Sortie ( TypeBarriere type, int semEtatIdExt, int memEtatIdExt,
			int semRequeteIdExt, int memRequeteIdExt, int semEntreeSortieIdExt,
			const char* nomCanalSortie )
{
	initialisation(type, semEtatIdExt, memEtatIdExt,
			semRequeteIdExt, memRequeteIdExt, semEntreeSortieIdExt, nomCanalSortie);
	for(;;)
	{
		moteur();
	}
}
