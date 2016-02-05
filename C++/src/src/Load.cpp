
    /*************************************************************************
                               Load  -  description
                                 -------------------
        début                : 16/1/2016
        copyright            : (C) 2016 par nsorin
    *************************************************************************/

    //---------- Réalisation de la classe <Load> (fichier Load) --

    //---------------------------------------------------------------- INCLUDE

    //-------------------------------------------------------- Include système
    using namespace std;
    #include <iostream>

    //------------------------------------------------------ Include personnel
    #include "../header/Load.h"

    //------------------------------------------------------------- Constantes

    //---------------------------------------------------- Variables de classe

    //----------------------------------------------------------- Types privés


    //----------------------------------------------------------------- PUBLIC
    //-------------------------------------------------------- Fonctions amies

    //----------------------------------------------------- Méthodes publiques
    bool Load::Do ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        // S'il s'agit d'un redo, inutile de relire le fichier
        if(undone == false)
        {
            //undone = false;
            opIndex = 0;
            tempObjects.clear();
            ops.clear();
            string line;
            ifstream ifs(fileName, ios::in);
            if(ifs)
            {
                int n = 0;
                while(getline(ifs, line))
                {
                    n++;
                    if(!parseLine(line))
                    {
                        // On supprime les objets qu'on avait commencé à créer
                        for(it_model i=mapObjects.begin(); i != mapObjects.end(); i++)
                        {
                            delete i->second;
                        }
                        mapObjects.clear();
                        cout << "#Could not parse line "<< n << " :  " << line << endl;
                        return false;
                    }
                }
                oldObjects = model;
                model = mapObjects;
                return true;
            }
            cout << "#Could not read file :   " << fileName << endl;
            return false;
        }
        else
        {
            oldObjects = model;
            model = mapObjects;
            return true;
        }
    } //----- Fin de Do

    bool Load::Undo ( map<string, Object*> & model )
    // Algorithme :
    //
    {
        undone = true;
        model = oldObjects;
        return true;
    } //----- Fin de Undo


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Load::Load ( string & data ) : fileName(data), opIndex(0)
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au constructeur de <Load>" << endl;
    #endif
        undone = false;
    } //----- Fin de Load


    Load::~Load ( )
    // Algorithme :
    //
    {
    #ifdef MAP
        cout << "Appel au destructeur de <Load>" << endl;
    #endif
        if(undone)
        {
            for(it_model i=mapObjects.begin(); i != mapObjects.end(); i++)
            {
                delete i->second;
            }
            mapObjects.clear();
        }
        else
        {
            for(it_model i=oldObjects.begin(); i != oldObjects.end(); i++)
            {
                delete i->second;
            }
            oldObjects.clear();
        }
    } //----- Fin de ~Load


    //------------------------------------------------------------------ PRIVE

    //----------------------------------------------------- Méthodes protégées

    //------------------------------------------------------- Méthodes privées
    bool Load::parseLine(string & line)
    {
        //cout << line << endl;
        unsigned int separator = line.find(" ");
    	string firstWord;
    	string data;
    	firstWord = line.substr(0, separator);
        data = line.substr(separator+1);
        //cout << "opIndex=" << opIndex << " / firstWord=" << firstWord << " / data=" << data << endl;
        if(firstWord == "S")
        {
            AddSegment cmd(data, true);
            if(opIndex == 0)
            {
                if(!cmd.Do(mapObjects))
                {
                    return false;
                }
            }
            else
            {
                if(!cmd.Do(tempObjects[opIndex-1]))
                {
                    return false;
                }
            }
        }
        else if(firstWord == "R")
        {
            AddRectangle cmd(data, true);
            if(opIndex == 0)
            {
                if(!cmd.Do(mapObjects))
                {
                    return false;
                }
            }
            else
            {
                if(!cmd.Do(tempObjects[opIndex-1]))
                {
                    return false;
                }
            }
        }
        else if(firstWord == "PC")
        {
            AddPolygone cmd(data);
            if(opIndex == 0)
            {
                if(!cmd.Do(mapObjects))
                {
                    return false;
                }
            }
            else
            {
                if(!cmd.Do(tempObjects[opIndex-1]))
                {
                    return false;
                }
            }
        }
        else if(firstWord == "OI")
        {
            InterObject* io = new InterObject(data);
            map<string, Object*> m;
            ops.push_back(io);
            tempObjects.push_back(m);
        }
        else if(firstWord == "OR")
        {
            UnionObject* uo = new UnionObject(data);
            map<string, Object*> m;
            ops.push_back(uo);
            tempObjects.push_back(m);
        }
        else if(firstWord == "{")
        {
            opIndex++;
        }
        else if(firstWord == "}")
        {
            if(opIndex > 0)
            {
                opIndex--;
                for(it_model i = tempObjects[opIndex].begin(); i != tempObjects[opIndex].end(); i++)
                {
                    ops[opIndex]->AddObject(i->second);
                }
                if(opIndex == 0)
                {
                    mapObjects[ops[0]->GetName()] = ops[0];
                }
                else
                {
                    ops[opIndex-1]->AddObject(ops[opIndex]);
                }
                // On supprime les objets temporaires de ce block
                ops.pop_back();
                for(it_model i = tempObjects.back().begin(); i != tempObjects.back().end(); i++)
                {
                    delete i->second;
                }
                tempObjects.back().clear();
                tempObjects.pop_back();
            }
        }
        return true;
    }

