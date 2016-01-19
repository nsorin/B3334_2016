/*************************************************************************
                           Controller -  description
                             -------------------
    début                : 24/11/2015
    copyright            : (C) 2015 par B3334
*************************************************************************/

//---------- Réalisation de la classe <Controller> (fichier Controller.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <deque>
#include <map>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../header/Command.h"
#include "../header/Object.h"
//-------------------------------------------------- Déclarations Méthodes
void treatCmd(string cmd);

//------------------------------------------------------------------- Main
int main(int argc, char** argv)
{
    deque<Command> dequeCmd;
    map<string,Object> mapObjects;
    Command lastUndoCmd();
    return 0;
}

void treatCmd(string cmd)
{

}
