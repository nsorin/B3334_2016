/*************************************************************************
                           ENTREE  -  description
                             -------------------
    début                : 18/03/16
    copyright            : (C) B3334 par B3334
*************************************************************************/

//---------- Réalisation de la tâche <ENTREE> (fichier ENTREE.cpp) ---

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Entree.h"
#include "Donnees.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques


//------------------------------------------------------ Fonctions privées
static void initialisation()
{

} //----- fin de initialisation

static void moteur()
{

} //----- fin de moteur

static void destruction()
{


  //Suicide de la tâche
  exit(0);
} //----- fin de destruction

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

void Entree()
{
  //Phase d'initialisation
  initialisation();

  //Phase moteur
  for(;;)
  {
    moteur();
  }
} //----- fin de Menu
