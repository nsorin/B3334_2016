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

//------------------------------------------------------ Fonctions privées
static void initialisation()
// Algorithme :
//
{
  //Ouverture des canaux de communication
  descCanalBPP = open(NOM_CANAL_BPP, O_WRONLY);
  descCanalBPA = open(NOM_CANAL_BPA, O_WRONLY);
  descCanalGB = open(NOM_CANAL_GB, O_WRONLY);
  descCanalSortie = open(NOM_CANAL_SORTIE, O_WRONLY);
} //----- fin de initialisation

static void moteur()
// Algorithme :
//
{
  Menu();
} //----- fin de moteur

static void destruction()
// Algorithme :
//
{
  //Fermeture des canaux de communication
  close(descCanalBPP);
  close(descCanalBPA);
  close(descCanalGB);
  close(descCanalSortie);
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Simu()
// Algorithme :
//
{
  // Phase d'initialisation
  initialisation();

  // Phase moteur
  for(;;)
  {
    moteur();
  }
} //----- fin de Menu

void Commande(char code, unsigned int valeur)
// Algorithme :
//
{
  if(code == 'e' || code == 'E')
  {
    exit(0);
  }
  else if(code == 'p' || code == 'P')
  {
    switch (valeur) {
      case 1:
        char prof = 'P';
        write(descCanalBPP,&prof,sizeof(char));
        break;
      case 3:
        char prof = 'P';
        write(descCanalGB,&prof,sizeof(char));
        break;
      default:
    }
  }
  else if(code == 'a' || code == 'A')
  {
    
  }
  else if(code == 's' || code == 'S')
  {

  }
} //----- fin de Commande
