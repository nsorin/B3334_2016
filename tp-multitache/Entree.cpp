/*************************************************************************
                           ENTREE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Réalisation de la tâche <ENTREE> (fichier ENTREE.cpp) ---

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
#include "Entree.h"
#include "Donnees.h"

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
static const char* nomCanalEntree;
static int descCanalSimu;
static map<pid_t,Voiture> voituriersEnService;

//------------------------------------------------------ Fonctions privées
static void destruction(int noSignal)
{
  // On annule l'impact des signaux SIGCHLD au cas ou un
  // voiturier mourrait dans l'intervalle de temps
  struct sigaction actionChild;
  actionChild.sa_handler = SIG_IGN;
  sigemptyset(&actionChild.sa_mask);
  actionChild.sa_flags = 0;
  sigaction(SIGUSR2, &actionChild, NULL);

  // Demande de suicide à tous les voituriers en service
  for(map<pid_t,Voiture>::iterator it=voituriersEnService.begin(); it!=voituriersEnService.end(); it++)
  {
    kill(it->first,SIGUSR2);
  }
  // Attente des réponses des voituriers
  for(map<pid_t,Voiture>::iterator it=voituriersEnService.begin(); it!=voituriersEnService.end(); it++)
  {
    waitpid(it->first,NULL,0);
  }
  // Fermeture du canal de communication
  close(descCanalSimu);
  // Suicide de la tâche
  exit(0);
} //----- fin de destruction

static void mortVoiturier(int noSignal)
{
  // Affichage de la voiture à la place
  // AfficherPlace()
} //----- fin de mortVoiturier

static void initialisation(TypeBarriere barriereExt, int semEtatIdExt, int memEtatIdExt,
  int semRequeteIdExt, int memRequeteIdExt, int semEntreeSortieIdExt, const char* nomCanalEntreeExt)
{
  // Initialisation des variables static
  barriere = barriereExt;
  semEtatId = semEtatIdExt;
  memEtatId = memEtatIdExt;
  semRequeteId = semRequeteIdExt;
  memRequeteId = memRequeteIdExt;
  semEntreeSortieId = semEntreeSortieIdExt;
  nomCanalEntree = nomCanalEntreeExt;

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
  descCanalSimu = open(nomCanalEntree, O_RDONLY);
} //----- fin de initialisation

static void moteur()
{
  // Lecture de l'arrivée d'un véhicule
  Voiture voiture;
  if(read(descCanalSimu, &voiture, sizeof(Voiture) > 0))
  {
    // Affichage de la voiture sur l'IHM
    DessinerVoitureBarriere(barriere, voiture.type);

    // Création des divers sembuf
    struct sembuf reservation = {0, 1, 0};
    struct sembuf attente = {0, 0, 0};
    struct sembuf liberation = {0, -1, 0};

    // Attente du sémaphore d'état à 0 = Mémoire Partagée libre
    while(semop(semEtatId, &attente, 1)==-1 && errno==EINTR);
    // Réservation du sémaphore d'état
    while(semop(semEtatId, &reservation, 1)==-1 && errno==EINTR);
    // Attachement à la mémoire partagée d'état du parking
    StructMemEtat* memEtat = (StructMemEtat*) shmat(memEtatId, NULL, 0);
    // Lecture de la mémoire partagée d'état du parking
    if(memEtat->nbPlacesPrises<NB_PLACES)
    {
      // Modification du nombre de places prises
      memEtat->nbPlacesPrises++;
      // Détachement de la mémoire partagée d'état du parking
      shmdt(memEtat);
      // Libération du sémaphore d'état
      while(semop(semEtatId, &liberation, 1)==-1 && errno==EINTR);
      // Création du voiturier en charge de la voiture
      pid_t voiturier = GarerVoiture(barriere);
      // Ajout du voiturier dans la map des voituriers en service
      voituriersEnService.insert(pair<pid_t, Voiture>(voiturier,voiture));
    }
    else
    {
      // Détachement de la mémoire partagée d'état du parking
      shmdt(memEtat);
      // Libération du sémaphore d'état
      while(semop(semEtatId, &liberation, 1)==-1 && errno==EINTR);
      // Attente du sémaphore de requêtes à 0 = Mémoire Partagée libre
      while(semop(semRequeteId, &attente, 1)==-1 && errno==EINTR);
      // Réservation du sémaphore de requêtes
      while(semop(semRequeteId, &reservation, 1)==-1 && errno==EINTR);
      // Attachement à la mémoire partagée des requêtes
      StructMemRequete* memReq = (StructMemRequete*) shmat(memRequeteId,NULL,0);
      // Ajout de la requête
      RequetePlace req;
      req.barriere = barriere;
      req.voiture = voiture;
      req.arrivee = 3;
      memReq->requetes[barriere-1] = req;
      // Détachement de la mémoire partagée des requêtes
      shmdt(memReq);
      // Libération du sémaphore de requêtes
      while(semop(semRequeteId, &liberation, 1)==-1 && errno==EINTR);
      //Affichage de la requête
      AfficherRequete(req.barriere, req.voiture.type, req.arrivee);
      // Attente du sémaphore de la sortie
      while(semop(semRequeteId, &attente, 1)==-1 && errno==EINTR);
      // Attente du sémaphore d'état à 0 = Mémoire Partagée libre
      while(semop(semEtatId, &attente, 1)==-1 && errno==EINTR);
      // Réservation du sémaphore d'état
      while(semop(semEtatId, &reservation, 1)==-1 && errno==EINTR);
      // Attachement à la mémoire partagée d'état du parking
      StructMemEtat* memEtat = (StructMemEtat*) shmat(memEtatId, NULL, 0);
      // Modification du nombre de places prises
      memEtat->nbPlacesPrises++;
      // Détachement de la mémoire partagée d'état du parking
      shmdt(memEtat);
      // Libération du sémaphore d'état
      while(semop(semEtatId, &liberation, 1)==-1 && errno==EINTR);
      // Création du voiturier en charge de la voiture
      pid_t voiturier = GarerVoiture(barriere);
      // Ajout du voiturier dans la map des voituriers en service
      voituriersEnService.insert(pair<pid_t, Voiture>(voiturier,voiture));
    }
  }
  else
  {
    cerr << "Erreur lors de la lecture du canal Simu";
  }
} //----- fin de moteur

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Entree(TypeBarriere barriereExt, int semEtatIdExt, int memEtatIdExt,
  int semRequeteIdExt, int memRequeteIdExt, int semEntreeSortieIdExt, const char* nomCanalEntreeExt)
{
  //Phase d'initialisation
  initialisation(barriereExt, semEtatIdExt, memEtatIdExt, semRequeteIdExt, memRequeteIdExt,
    semEntreeSortieIdExt, nomCanalEntreeExt);

  //Phase moteur
  for(;;)
  {
    moteur();
  }
} //----- fin de Menu
