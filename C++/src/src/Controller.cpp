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
#include <sstream>
#include "InterObject.h"
#include "UnionObject.h"
#include "Polygone.h"
#include "Rectangle.h"
#include "Segment.h"
#include "Point.h"
#include "Intersection.h"
#include "Union.h"
#include "Clear.h"
#include "Save.h"
#include "Load.h"
#include "Move.h"
#include "Delete.h"
#include "AddPolygone.h"
#include "AddRectangle.h"
#include "AddSegment.h"

using namespace std;

//------------------------------------------------------ Include personnel
#include "../header/Command.h"
#include "../header/Object.h"
//-------------------------------------------------- Déclarations Méthodes
void treatCmd(string cmd);

//------------------------------------------------------------------- Main
int main()
{
    Command *currentCmd;
    deque<Command*> dequeCmd;
    map<string,Object> mapObjects;
    Command lastUndoCmd();
    string cmd;
    string data;
    while(true)
    {
    	getline(cin, cmd);
    	unsigned int separator = cmd.find(" ");
    	firstWord = cmd.substr(0, separator);
    	data = cmd.substr(separator);
    	if(firstWord == exit)
    	{
    		return 0;
    	}
    	else if(firstWord == "S")
    	{
    		currentCmd = new AddSegment(data);
    	}
    	else if(firstWord == "R")
    	{
    		currentCmd = new AddRectangle(data);
    	}
    	else if(firstWord == "PC")
    	{
    		currentCmd = new AddPolygone(data);
    	}
    	else if(firstWord == "OR")
    	{
    		currentCmd = new Union(data);
    	}
    	else if(firstWord == "OI")
    	{
    		currentCmd = new Intersection(data);
    	}
    	else if(firstWord == "HIT")
    	{

    	}
    	else if(firstWord == "DELETE")
    	{
    		currentCmd = new Delete(data);
    	}
    	else if(firstWord == "MOVE")
    	{
    		currentCmd = new Move(data);
    	}
    	else if(firstWord == "LIST")
    	{

    	}
    	else if(firstWord == "UNDO")
    	{

    	}
    	else if(firstWord == "REDO")
    	{

    	}
    	else if(firstWord == "LOAD")
    	{
    		currentCmd = new Load(data);
    	}
    	else if(firstWord == "SAVE")
    	{
    		currentCmd = new Data(data);
    	}
    	else if(firstWord == "CLEAR")
    	{
    		currentCmd = new Clear();
    	}
    	//sale
    	if(currentCmd->Do(mapObjects))
    	{
    		dequeCmd.addFirst(currentCmd);
    		//Enlever dernière
    	}
    	else
    	{
    		delete currentCmd;
    	}
    }
}

void processCmd(string cmd)
{

}
