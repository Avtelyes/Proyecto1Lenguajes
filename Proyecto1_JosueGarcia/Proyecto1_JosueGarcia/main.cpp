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
    
    /* Definición de los vectores que contienen los distintos elementos/tokens a identificar */
    vector<char> digitos={'0','1','2','3','4','5','6','7','8','9'};
    vector<char> operandos={'+','-','/','*','^'};
    vector<char> variables={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    /* Vectores que contendrán los tokens identificados con su descripción */
    vector<string> token_identificado;
    vector<string> identificacion_token;
    
    /* Definición de los estados del autómata */
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
    
    /* Se definen los valores de los atributos de cada estado así como los tokens que deben de procesar e identificación de tokens en caso de que el estado siguiente sea uno final */
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
    estado4->addEventEnd('#', estado5, "Real");
    
    estado8->setEstado("8");
    estado8->addEvent('+', estado9);
    estado8->addEvent('-', estado9);
    
    estado9->setEstado("9");
    estado9->addArrayEvent(digitos, estado9);
    estado9->addEventEnd(' ', estado10, "Real");
    estado9->addEventEnd('(', estado10, "Real");
    estado9->addEventEnd(')', estado10, "Real");
    estado9->addArrayEventEnd(operandos, estado10, "Real");
    estado9->addEventEnd('#', estado10, "Real");
    
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
    estado16->addEventEnd('#', estado17, "Variable");
    
    estado18->setEstado("18");
    estado18->addArrayEventEnd(digitos, estado19, "Paréntesis que abre");
    estado18->addEventEnd(' ', estado19, "Paréntesis que abre");
    estado18->addEventEnd('+', estado19, "Paréntesis que abre");
    estado18->addEventEnd('/', estado19, "Paréntesis que abre");
    estado18->addEventEnd('*', estado19, "Paréntesis que abre");
    estado18->addEventEnd('^', estado19, "Paréntesis que abre");
    estado18->addArrayEventEnd(variables, estado19, "Paréntesis que abre");
    estado18->addEventEnd('-', estado21, "Paréntesis que abre");
    
    estado21->setEstado("21");
    estado21->setEstadoFin(true);
    estado21->addArrayEvent(digitos, estado1);
    estado21->addEventEnd(' ', estado22, "Resta");
    estado21->addEventEnd('(', estado22, "Resta");
    estado21->addArrayEventEnd(variables, estado22, "Resta");
    
    
    /* Se definen las variables para abrir el archivo de texto que en este caso se llama prueba.txt */
    string line;
    string tokenI="";
    int linea = 1;
    ifstream archivo("prueba.txt");
    if (archivo.is_open())
    {
        //Definición de Estados auxiliares
        Estado *aux = estado0;
        Estado *aux2 = NULL;
        
        //Definición del while que obtiene cada línea del archivo
        while ( getline (archivo,line) )
        {
            //Definición del for que clasifica cada caracter de la linea
            for(int i=0; i<line.length(); ++i)
            {
                //Se obtiene el estado siguiente analizando el caracter actual
                aux2 = aux->toNext(line.at(i));
                if(aux2 == estado0 || (aux2 != NULL && aux2->getEstadoFin() == true))
                {
                    //Al ser estado final se añade el conjunto de caracteres a tokens identificados junto con la descripción que se obtiene con la funcion getFin
                    token_identificado.push_back(tokenI);
                    identificacion_token.push_back(aux->getFin(line.at(i)));
                    tokenI = ""; //Se reinicia el string de caracteres
                    if(line.at(i) != ' ')
                        tokenI += line.at(i);
                }
                else
                {
                    tokenI += line.at(i);
                }
                aux = aux2;
                
                if(aux == NULL)
                {
                    //En caso de detectar un estado siguiente nulo quiere decir que hay un error y se desplegará un error diciendo cuál fue el caracter del problema en qué línea y termina el programa
                    cout << "Error al procesar el token " << line.at(i) << " en la linea " << linea << endl;
                    exit(EXIT_FAILURE);
                }
                else if(aux == estado0)
                {
                    //Si queda un elemento por analizar al estar en el estado cero que es el inicial se vuelve a ejecutar un analisis
                    aux = aux->toNext(line.at(i));
                    if(aux == estado0)
                    {
                        token_identificado.push_back(tokenI);
                        identificacion_token.push_back(aux->getFin(line.at(i)));
                        tokenI = "";
                    }
                }
            }
            ++linea; //Se hace el correspondiente incremento
            if(tokenI.length() > 0)
            {
                //Si queda aún así algun elemento por analizar después del término de la línea se ejecuta lo siguiente.
                if(aux->toNext('#') == estado0)
                {
                    //Al declarar el caracter # como fin de línea se le manda al estado que lo procese para ver si puede quedar así la escritura del usuario o si hay un error
                    token_identificado.push_back(tokenI);
                    identificacion_token.push_back(aux->getFin('#'));
                    tokenI = "";
                    aux = estado0;
                }
                else if (aux->toNext('#') == NULL)
                {
                    //Al igual que en la identificación de error anterior te dice en que línea y que caracter y termina el programa
                    cout << "Error al procesar el token " << tokenI.back() << " en la linea " << linea-1 << endl;
                    exit(EXIT_FAILURE);
                }
            }
        }
        archivo.close(); //Se cierra el archivo
    }
    
    //Error por si no se puede abrir el archivo
    else cout << "No se pudo abrir el archivo" << endl;
    
    //Inicio de la tabla con un tabular
    cout << "Token\tTipo" << endl;
    
    for(int i=0; i<token_identificado.size(); ++i)
    {
        //Se imprimen todos los tokens identificados con su descripción
        if(token_identificado[i] != "")
            cout << token_identificado[i] << "\t" << identificacion_token[i] << endl;
    }
    
    return 0;
}
