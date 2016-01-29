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

/* Se define la clase Estado que representa cada estado del automata */

class Estado
{
private:
    string estado; //Nombre del estado
    vector<char> tokens; //Vector que contendrá los tokens a procesar
    vector<Estado *> siguiente; //Vector que contiene apuntadores a otros Estados
    vector<string> fin; //Vector que contiene la identificación de los tokens
    bool estadoFin; //Booleano para saber si se es un estado final
    
public:
    Estado()
    {
        estado = "";
        estadoFin = false;
    }
    Estado(string es, char tk, Estado *sig)
    {
        estado = es;
        tokens.push_back(tk);
        siguiente.push_back(sig);
        estadoFin = false;
    }
    Estado *toNext(char tok)
    {
        //Método que regresa el apuntador al siguiente estado si hay uno
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
        //Se añaden los eventos con los cuales pasaran al siguiente estado
        tokens.push_back(tok);
        siguiente.push_back(sig);
        fin.push_back("");
    }
    void addArrayEvent(vector<char> arr, Estado *sig)
    {
        //Para hacer más dinámico se puede añadir un vector que contiene varios tokens para despues poderlos identificar
        for(int i=0; i<arr.size(); ++i)
        {
            tokens.push_back(arr[i]);
            siguiente.push_back(sig);
            fin.push_back("");
        }
    }
    void addEventEnd(char tok, Estado *sig, string end)
    {
        //Se identifica con cuales tokens te llevarán a un estado final si es que hay y se agrega al vector fin el detalle del token identificado
        tokens.push_back(tok);
        siguiente.push_back(sig);
        fin.push_back(end);
    }
    void addArrayEventEnd(vector<char> arr, Estado *sig, string end)
    {
        //Al igual que el método anterior tiene el mismo funcionamiento pero más dinámico para un vector de tokens que se defina
        for(int i=0; i<arr.size(); ++i)
        {
            tokens.push_back(arr[i]);
            siguiente.push_back(sig);
            fin.push_back(end);
        }
    }
    /* Métodos set y get para los atributos privados */
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
    string getFin(char end)
    {
        string aux = "";
        for(int i=0; i<tokens.size(); ++i)
        {
            if(tokens[i] == end)
            {
                aux = fin[i];
                break;
            }
        }
        return aux;
    }
    void setEstadoFin(bool fn)
    {
        estadoFin = fn;
    }
    bool getEstadoFin()
    {
        return estadoFin;
    }
};

#endif /* automata_hpp */
