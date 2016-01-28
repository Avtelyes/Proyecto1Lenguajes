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
    Estado *estado21 = new Estado();
    Estado *estado22 = estado0;
    
    estado0->setEstado("0");
    estado0->addEvent(' ', estado0);
    estado0->addArrayEvent(digitos, estado1);
    estado0->addEventEnd('=', estado11, "Asignación");
    estado0->addEventEnd('+', estado11, "Suma");
    estado0->addEventEnd('*', estado11, "Multiplicación");
    estado0->addEventEnd('-', estado11, "Resta");
    estado0->addEventEnd(')', estado11, "Paréntesis que cierra");
    estado0->addEventEnd('^', estado11, "Potencia");
    estado0->addEvent('/', estado12);
    estado0->addArrayEvent(variables, estado16);
    estado0->addEvent('(', estado18);
    
    estado1->setEstado("1");
    estado1->addArrayEvent(digitos, estado1);
    estado1->addEventEnd('(', estado2, "Entero");
    estado1->addEventEnd(')', estado2, "Entero");
    estado1->addEventEnd(' ', estado2, "Entero");
    estado1->addEventEnd('#', estado2, "Entero");
    estado1->addEvent('.', estado3);
    estado1->addArrayEventEnd(operandos, estado7, "Entero");
    estado1->addEvent('e', estado8);
    estado1->addEvent('E', estado8);
    
    estado3->setEstado("3");
    estado3->addArrayEvent(digitos, estado4);
    
    estado4->setEstado("4");
    estado4->addArrayEvent(digitos, estado4);
    estado4->addEvent('e', estado8);
    estado4->addEvent('E', estado8);
    estado4->addEventEnd(' ', estado5,"Real");
    estado4->addEventEnd('(', estado5,"Real");
    estado4->addEventEnd(')', estado5, "Real");
    estado4->addArrayEventEnd(operandos, estado5, "Real");
    
    estado8->setEstado("8");
    estado8->addEvent('+', estado9);
    estado8->addEvent('-', estado9);
    
    estado9->setEstado("9");
    estado9->addArrayEvent(digitos, estado9);
    estado9->addEventEnd(' ', estado10, "Real");
    estado9->addEventEnd('(', estado10, "Real");
    estado9->addEventEnd(')', estado10, "Real");
    estado9->addArrayEventEnd(operandos, estado10, "Real");
    
    estado12->setEstado("12");
    estado12->addEventEnd('(', estado13, "División");
    estado12->addEventEnd(' ', estado13, "División");
    estado12->addArrayEventEnd(digitos, estado13, "División");
    estado12->addEvent('/', estado14);
    
    estado14->setEstado("14");
    estado14->addArrayEvent(digitos, estado15);
    estado14->addArrayEvent(operandos, estado15);
    estado14->addArrayEvent(variables, estado15);
    estado14->addEvent(' ', estado15);
    estado14->addEvent('(', estado15);
    estado14->addEvent(')', estado15);
    
    estado15->setEstado("15");
    estado15->addArrayEvent(digitos, estado15);
    estado15->addArrayEvent(operandos, estado15);
    estado15->addArrayEvent(variables, estado15);
    estado15->addEvent(' ', estado15);
    estado15->addEvent('(', estado15);
    estado15->addEvent(')', estado15);
    estado15->addEventEnd('#', estado20, "Comentario");
    
    estado16->setEstado("16");
    estado16->addArrayEvent(variables, estado16);
    estado16->addEventEnd(' ', estado17, "Variable");
    estado16->addEventEnd('(', estado17, "Variable");
    estado16->addEventEnd(')', estado17, "Variable");
    estado16->addEventEnd('=', estado17, "Variable");
    estado16->addArrayEventEnd(operandos, estado17, "Variable");
    
    estado18->setEstado("18");
    estado18->addArrayEventEnd(digitos, estado19, "Paréntesis que abre");
    estado18->addEventEnd(' ', estado19, "Paréntesis que abre");
    estado18->addArrayEventEnd(operandos, estado19, "Paréntesis que abre");
    estado18->addArrayEventEnd(variables, estado19, "Paréntesis que abre");
    estado18->addEvent('-', estado21);
    
    estado21->setEstado("21");
    estado21->setEstadoFin(true);
    estado21->addArrayEvent(digitos, estado1);
    estado21->addEventEnd(' ', estado22, "Resta");
    estado21->addEventEnd(' ', estado22, "Resta");
    estado21->addArrayEventEnd(variables, estado22, "Resta");
    
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
    string tokenI="";
    int linea = 1;
    ifstream archivo("prueba.txt");
    if (archivo.is_open())
    {
        Estado *aux = estado0;
        Estado *aux2 = NULL;
        while ( getline (archivo,line) )
        {
            for(int i=0; i<line.length(); ++i)
            {
                //cout << line.at(i) << '\n';
                aux2 = aux->toNext(line.at(i));
                if(aux2 == estado0)
                {
                    token_identificado.push_back(tokenI);
                    identificacion_token.push_back(aux->getFin(line.at(i)));
                    tokenI = "";
                    tokenI += line.at(i);
                }
                else
                {
                    tokenI += line.at(i);
                }
                aux = aux2;
                
                if(aux == NULL)
                {
                    cout << "Error al procesar el token " << line.at(i) << " en la linea " << linea << endl;
                    exit(EXIT_FAILURE);
                }
                else if(aux == estado0)
                {
                    aux = aux->toNext(line.at(i));
                    if(aux == estado0)
                    {
                        token_identificado.push_back(tokenI);
                        identificacion_token.push_back(aux->getFin(line.at(i)));
                        tokenI = "";
                    }
                    //aux = aux->toNext(line.at(i));
                }
            }
            ++linea;
            //aux = aux->toNext('#');
            if(aux->toNext('#') == estado0)
            {
                token_identificado.push_back(tokenI);
                identificacion_token.push_back(aux->getFin('#'));
                tokenI = "";
                aux = estado0;
            }
            else if (aux->toNext('#') == NULL)
            {
                cout << "Error al procesar el token " << tokenI.back() << " en la linea " << linea-1 << endl;
                exit(EXIT_FAILURE);
            }
        }
        archivo.close();
    }
    
    else cout << "No se pudo abrir el archivo" << endl;
    
    cout << "Token\tTipo" << endl;
    
    for(int i=0; i<token_identificado.size(); ++i)
    {
        cout << token_identificado[i] << "\t" << identificacion_token[i] << endl;
    }
    
    return 0;
}
