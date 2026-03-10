//
//  main.c
//  es6__29_10_20
//
//  Created by Cendron Pietro on 03/12/20.
//
//  Prg: Stampa un array senza usare un indice, operando con un puntatore.

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(void)
{
    char frase[SIZE];
    
    gets(frase);
    for (char *c = frase; *c!='\0'; c++)
    {
        printf("%c\n\n", *c);
    }
    
    return 0;
}
