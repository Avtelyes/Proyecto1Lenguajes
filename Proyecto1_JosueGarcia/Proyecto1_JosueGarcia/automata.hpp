//
//  automata.hpp
//  Proyecto1_JosueGarcia
//
//  Created by Josué Carlos García Puig on 25/01/16.
//  Copyright © 2016 Josue Garcia. All rights reserved.
//

#ifndef automata_hpp
#define automata_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

class Estado;

class Automata
{
private:
    Estado *actual;
    vector<string> tokens;
    vector<Estado *> siguiente;
    
public:
    Automata()
    {
        actual = NULL;
    }
    Automata(Estado *act, string tok , Estado *sig)
    {
        actual = act;
        tokens.push_back(tok);
        siguiente.push_back(sig);
    }
    void addState(Estado *act, string tok , Estado *sig)
    {
        actual = act;
        tokens.push_back(tok);
        siguiente.push_back(sig);
    }
};

class Estado
{
private:
    string estado;
    vector<char> tokens;
    //vector<string> eventos;
    vector<Estado *> siguiente;
    
public:
    Estado()
    {
        estado = "";
    }
    Estado(string es, char tk, Estado *sig)
    {
        estado = es;
        tokens.push_back(tk);
        siguiente.push_back(sig);
    }
    Estado *toNext(char tok)
    {
        Estado *aux = NULL;
        
        for(int i=0; i<tokens.size(); ++i)
        {
            if(tok == tokens[i])
            {
                aux = siguiente[i];
                break;
            }
            else
            {
                aux = NULL;
            }
        }
        return aux;
    }
    void addEvent(char tok, Estado *sig)
    {
        tokens.push_back(tok);
        siguiente.push_back(sig);
    }
    void addArrayEvent(vector<char> arr, Estado *sig)
    {
        for(int i=0; i<arr.size(); ++i)
        {
            tokens.push_back(arr[i]);
            siguiente.push_back(sig);
        }
    }
    void setEstado(string st)
    {
        estado = st;
    }
    string getEstado()
    {
        return estado;
    }
    void getEvents(char tok)
    {
        for(int i=0; i<tokens.size(); ++i)
        {
            cout << tokens[i] << "\t" << siguiente[i]->getEstado();
        }
    }
};

#endif /* automata_hpp */
