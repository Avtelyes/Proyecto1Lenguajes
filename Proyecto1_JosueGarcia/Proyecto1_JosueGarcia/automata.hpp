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
};

class Estado
{
private:
    string estado;
    string token;
    //vector<string> eventos;
    string sig_estado;
    
public:
    Estado()
    {
        estado = "";
        token = "";
        sig_estado = "";
    }
    Estado(string es, string tk, string sig)
    {
        estado = es;
        token = tk;
        sig_estado = sig;
    }
    int hacia_estado(string carac)
    {
        if (carac == token)
        {
            return stoi(estado);
        }
        else
            return 0;
    }
    void setEstado(string st)
    {
        estado = st;
    }
    string getEstado()
    {
        return estado;
    }
    void setToken(string tok)
    {
        token = tok;
    }
    string getToken()
    {
        return token;
    }
    void setSigEs(string ses)
    {
        sig_estado = ses;
    }
    string getSigEs()
    {
        return sig_estado;
    }
};

#endif /* automata_hpp */
