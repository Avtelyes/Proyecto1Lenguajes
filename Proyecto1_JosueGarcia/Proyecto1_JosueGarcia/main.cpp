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
    
    
    
    Estado *estado0 = new Estado();
    Estado *estado1 = new Estado();
    Estado *estado2 = new Estado();
    Estado *estado3 = new Estado();
    
    Estado matriz[10][10];
    
    string mensaje = "87*9";
    
    estado0->setEstado("0");
    estado0->setToken("8");
    estado0->setSigEs("1");
    
    //cout << estado0->getSigEs() << endl;
    
    estado1->setEstado("1");
    estado1->setToken("7");
    estado1->setSigEs("1");
    
    estado2->setEstado("2");
    estado2->setToken("*");
    estado2->setSigEs("1");
    
    string line;
    ifstream archivo("prueba.txt");
    if (archivo.is_open())
    {
        while ( getline (archivo,line) )
        {
            for(int i=0; i<line.length(); ++i)
            {
                cout << line.at(i) << '\n';
            }
        }
        archivo.close();
    }
    
    else cout << "Unable to open file" << endl;
    
    return 0;
}
