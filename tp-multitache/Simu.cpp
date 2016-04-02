/*************************************************************************
                           SIMU  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Réalisation de la tâche <SIMU> (fichier SIMU.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Simu.h"
#include "Menu.h"
#include "Donnees.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques
static int descCanalBPP;
static int descCanalBPA;
static int descCanalGB;
static int descCanalSortie;
static unsigned int nombreVoitures;

//------------------------------------------------------ Fonctions privées
static void initialisation()
{
  //Ouverture des canaux de communication
  descCanalBPP = open(NOM_CANAL_BPP, O_WRONLY);
  descCanalBPA = open(NOM_CANAL_BPA, O_WRONLY);
  descCanalGB = open(NOM_CANAL_GB, O_WRONLY);
  descCanalSortie = open(NOM_CANAL_SORTIE, O_WRONLY);

  //Initialisation du compteur de voitures
  nombreVoitures = 0;
} //----- fin de initialisation

static void moteur()
{
  Menu();
} //----- fin de moteur

static void destruction()
{
  //Fermeture des canaux de communication
  close(descCanalBPP);
  close(descCanalBPA);
  close(descCanalGB);
  close(descCanalSortie);

  //Suicide de la tâche
  exit(0);
} //----- fin de destruction

static void attribuerNumVoiture(Voiture * voiture)
{
  if(nombreVoitures<999)
  {
    voiture->num = ++nombreVoitures;
  }
  else
  {
    nombreVoitures = 1;
    voiture->num = nombreVoitures;
  }
}

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Simu()
{
  //Phase d'initialisation
  initialisation();

  //Phase moteur
  for(;;)
  {
    moteur();
  }
} //----- fin de Menu

void Commande(char code, unsigned int valeur)
{
  if(code == 'e' || code == 'E')
  {
    //Phase de destruction
    destruction();
  }
  else if(code == 'p' || code == 'P')
  {
    //Création de la voiture
    Voiture voiture;
    voiture.type = PROF;
    attribuerNumVoiture(&voiture);

    //Envoie de la requête à la porte correspondante
    switch (valeur) {
      case 1:
        write(descCanalBPP,&voiture,sizeof(Voiture));
        break;
      case 3:
        write(descCanalGB,&voiture,sizeof(Voiture));
        break;
    }
  }
  else if(code == 'a' || code == 'A')
  {
    //Création de la voiture
    Voiture voiture;
    voiture.type = AUTRE;
    attribuerNumVoiture(&voiture);

    //Envoie de la requête à la porte correspondante
    switch (valeur) {
      case 2:
        write(descCanalBPA,&voiture,sizeof(Voiture));
        break;
      case 3:
        write(descCanalGB,&voiture,sizeof(Voiture));
        break;
    }
  }
  else if(code == 's' || code == 'S')
  {
    write(descCanalSortie,&valeur,sizeof(unsigned int));
  }
} //----- fin de Commande
