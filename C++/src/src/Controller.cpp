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
#include <fstream>
#include <deque>
#include <map>
#include <sstream>

using namespace std;

//------------------------------------------------------ Include personnel
#include "../header/Command.h"
#include "../header/Object.h"
#include "../header/InterObject.h"
#include "../header/UnionObject.h"
#include "../header/Polygone.h"
#include "../header/Rectangle.h"
#include "../header/Segment.h"
#include "../header/Point.h"
#include "../header/Intersection.h"
#include "../header/Union.h"
#include "../header/Clear.h"
#include "../header/Load.h"
#include "../header/Move.h"
#include "../header/Delete.h"
#include "../header/AddPolygone.h"
#include "../header/AddRectangle.h"
#include "../header/AddSegment.h"

//-------------------------------------------------- Déclarations Méthodes
void List(map<string, Object*> & model);
bool Hit(map<string, Object*> & model, string & data);
bool Save(map<string, Object*> & model, string & fileName);

//------------------------------------------------------------------- Main
int main()
{
    Command *currentCmd;
    deque<Command*> dequeCmd;
    map<string,Object*> mapObjects;
    Command *lastUndoCmd = nullptr;
    string cmd = "";
    string data = "";
    while(true)
    {
    	getline(cin, cmd);
    	unsigned int separator = cmd.find(" ");
    	string firstWord;
    	if(separator == string::npos || separator >= cmd.size() )
    	{
            firstWord = cmd;
            data = "";
    	}
    	else
    	{
            firstWord = cmd.substr(0, separator);
            data = cmd.substr(separator+1);
    	}
    	if(firstWord == "EXIT")
    	{
    		return 0;
    	}
    	else if(firstWord == "LIST")
    	{
    		List(mapObjects);
    	}
    	else if(firstWord == "HIT")
    	{
            Hit(mapObjects, data);
    	}
    	else if(firstWord == "SAVE")
    	{
            Save(mapObjects, data);
    	}
    	else if(firstWord == "UNDO")
    	{
    		if(!dequeCmd.empty())
    		{
    			if(dequeCmd.front()->Undo(mapObjects))
    			{
    				cout << "OK" << endl;
    				if(lastUndoCmd != nullptr)
                    {
                        delete lastUndoCmd;
                        lastUndoCmd = nullptr;
                    }
    				lastUndoCmd = dequeCmd.front();
    				dequeCmd.pop_front();
    			}
    			else
    			{
                    cout << "ERR" << endl;
    			}
    		}
    	}
    	else if(firstWord == "REDO")
    	{
    		if(lastUndoCmd != nullptr)
    		{
    			if(lastUndoCmd->Do(mapObjects))
    			{
    				cout << "OK" << endl;
    				dequeCmd.push_front(lastUndoCmd);
    				lastUndoCmd = nullptr;
    			}
    			else
    			{
                    cout << "ERR" << endl;
    			}
    		}
    		else
    		{
                cout << "ERR" << endl;
    		}
    	}
    	else
    	{
    		if(firstWord == "S")
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
    		else if(firstWord == "DELETE")
    		{
    			currentCmd = new Delete(data);
    		}
    		else if(firstWord == "MOVE")
    		{
    			currentCmd = new Move(data);
    		}
    		else if(firstWord == "LOAD")
    		{
	    		currentCmd = new Load(data);
    		}
    		else if(firstWord == "CLEAR")
    		{
    			currentCmd = new Clear();
    		}
    		else
    		{
                cerr << "Unknown command" << endl;
                break; // temp
    		}

    		if(currentCmd->Do(mapObjects))
    		{
    			dequeCmd.push_front(currentCmd);
    			if(lastUndoCmd != nullptr)
                {
                    delete lastUndoCmd;
                    lastUndoCmd = nullptr;
                }
    			if(dequeCmd.size() > 20)
    			{
    				delete dequeCmd.back();
    				dequeCmd.pop_back();
    			}
    			cout << "OK" << endl;
    		}
    		else
    		{
    			cout << "ERR" << endl;
    			delete currentCmd;
    		}
    	}
    }
}

void List(map<string, Object*> & model)
{
    cout << "Liste of all objects :" << endl;
    for(it_model i = model.begin(); i != model.end(); i++)
    {
        //cout << i->first << endl;
        cout << *i->second;
    }
}

bool Hit(map<string, Object*> & model, string & data)
{
    istringstream iss(data);
    string name;
    iss >> name;
    if(model.find(name) == model.end())
    {
        cout << "ERR" << endl;
        return false;
    }
    int x;
    int y;
    iss >> x;
    iss >> y;
    Point p(x, y);
    bool result = model[name]->Contains(p);
    if(result)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return result;
}

bool Save(map<string, Object*> & model, string & fileName)
{
    ofstream ofs(fileName, ios::trunc);
    if(ofs)
    {
        for(it_model i = model.begin(); i != model.end(); i++)
        {
            ofs << *i->second;
        }
        ofs.close();
        cout << "OK" << endl;
        return true;
    }
    else
    {
        cout << "ERR" << endl;
        return false;
    }
}
