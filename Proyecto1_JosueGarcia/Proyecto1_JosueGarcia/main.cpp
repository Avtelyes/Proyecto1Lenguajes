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
    
    vector<char> digitos={'0','1','2','3','4','5','6','7','8','9'};
    vector<char> operandos={'+','-','/','*','^'};
    vector<char> variables={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    vector<string> token_identificado;
    vector<string> identificacion_token;
    
    Estado *estado0 = new Estado();
    Estado *estado1 = new Estado();
    Estado *estado2 = estado0;
    Estado *estado3 = new Estado();
    Estado *estado4 = new Estado();
    Estado *estado5 = estado0;
    Estado *estado6 = new Estado();
    Estado *estado7 = estado0;
    Estado *estado8 = new Estado();
    Estado *estado9 = new Estado();
    Estado *estado10 = estado0;
    Estado *estado11 = estado0;
    Estado *estado12 = new Estado();
    Estado *estado13 = estado0;
    Estado *estado14 = new Estado();
    Estado *estado15 = new Estado();
    Estado *estado16 = new Estado();
    Estado *estado17 = estado0;
    Estado *estado18 = new Estado();
    Estado *estado19 = estado0;
    Estado *estado20 = estado0;
    
    estado0->setEstado("0");
    estado0->addEvent(' ', estado0);
    
    /*string mensaje = "87*9";
    
    estado0->setEstado("0");
    estado0->addEvent('8', estado1);
    
    //cout << estado0->getSigEs() << endl;
    
    estado1->setEstado("1");
    estado1->addEvent('7', estado1);
    estado1->addEvent('*', estado2);
    
    estado2->setEstado("2");*/
    
    //automata->addState(estado0, "8", estado1);
    
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
