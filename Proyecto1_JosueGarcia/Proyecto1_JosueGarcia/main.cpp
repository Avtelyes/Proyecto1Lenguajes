//
//  main.cpp
//  Proyecto1_JosueGarcia
//
//  Created by Josué Carlos García Puig on 25/01/16.
//  Copyright © 2016 Josue Garcia. All rights reserved.
//

#include <iostream>
#include "automata.hpp"
#include <fstream>

int main(int argc, const char * argv[]) {
    
    Automata *automata = new Automata();
    
    Estado *estado0 = new Estado();
    Estado *estado1 = new Estado();
    Estado *estado2 = new Estado();
    Estado *estado3 = new Estado();
    
    string mensaje = "87*9";
    
    estado0->setEstado("0");
    estado0->addEvent('8', estado1);
    
    //cout << estado0->getSigEs() << endl;
    
    estado1->setEstado("1");
    estado1->addEvent('7', estado1);
    estado1->addEvent('*', estado2);
    
    estado2->setEstado("2");
    
    automata->addState(estado0, "8", estado1);
    
    string line;
    int linea = 1;
    ifstream archivo("prueba.txt");
    if (archivo.is_open())
    {
        Estado *aux = estado0;
        while ( getline (archivo,line) )
        {
            for(int i=0; i<line.length(); ++i)
            {
                //cout << line.at(i) << '\n';
                aux = aux->toNext(line.at(i));
                
                if(aux == NULL)
                {
                    cout << "Error al procesar el token " << line.at(i) << " en la linea " << linea << endl;
                    exit(EXIT_FAILURE);
                }
            }
            ++linea;
        }
        archivo.close();
    }
    
    else cout << "Unable to open file" << endl;
    
    return 0;
}
