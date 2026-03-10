//
//  main.c
//  es4__29_10_20
//
//  Created by Cendron Pietro on 02/12/20.
//
//  Prg: Giocare con le stringhe.

#include <stdio.h>
#include <string.h>
#define SIZE 1000

int main(void)
{
    char frase[SIZE],
         parola[10] = "ciao";
    //1. char *p;
    int  cont=0;
    
    printf("Insert a sentence.\n");
    fpurge(stdin);
    gets(frase);
    
    printf("Insert a word.\n");
    fpurge(stdin);
    scanf("%s", parola);
    
    printf("The value of my sentence is: %s\n", frase);
    printf("The pointer of my sentence is: %p\n", frase);
    
    printf("The value of my word is: %s\n", parola);
    printf("The pointer of my word is: %p\n", parola);
    
    /*1.
        //Funzione che cerca la parola all'interno della frase attraverso un puntatore '*p'.
        p = strstr(frase, parola);
     */
    
    
    /*2.
        //Funzione che permette di conoscere il numero di volte in cui la 'word' è presente all'interno di 'frase'.
        for (i=0; i<strlen(frase);i++)
        {
            if (strstr(&frase[i], parola)!= NULL)
            {
                //QUI HO TROVATO LA PAROLA
                cont++;
                i=i+ strlen(parola);
            }
            printf("%d", i);
        }
     */
    
    for (int i=0; i<strlen(frase);i++)
    {
        if (strstr(&frase[i], parola)!= NULL)
        {
            //QUI HO TROVATO LA PAROLA
            cont++;
            i += strlen(parola) + (strstr(&frase[i],parola) - &frase[i]);
            
        }
        
    }
    
    printf("%d\n", cont);
    
    return 0;
}
