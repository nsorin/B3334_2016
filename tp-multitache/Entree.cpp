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
  //Fermeture du canal de communication
  close(descCanalSimu);

  //Suicide de la tâche
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

    // Détachement de la mémoire partagée d'état du parking
    shmdt(memEtat);

    // Création du voiturier en charge de la voiture
    pid_t voiturier = GarerVoiture(barriere);
    // Ajout du voiturier dans la map des voituriers en service
    voituriersEnService.insert(pair<pid_t, Voiture>(voiturier,voiture));
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
