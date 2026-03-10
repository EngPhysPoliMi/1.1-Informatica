//
//  main.c
//  es3__05_11_20
//
//  Created by Cendron Pietro on 15/12/20.
//
//  PRG: 1. Come stampare parte di una stringa.
//       2. Funzione strtok -> Sudduvidere una stringa in 'token'.
//       3. Funzione strncpy -> Sudduvidere una stringa in 'token'.
//       4. Esperimento sulla funzione strtok -> Sudduvidere una stringa in 'token' con un array di puntatori.
//
//  N.B.: è più conveniente usare '2.' rispetto a '3.'. La migliore da usare è la '4.'.

#include <stdio.h>
#include <string.h>
#define LNGTH 30

int main()
{
    
    
    // 1. Come stampare parte di una stringa.
    
    char string[LNGTH]= "Ciao, mi chiamo Pietro.";
    printf("%.8s\n\n", string);

    
    
    // 2. Funzione strtok -> Sudduvidere una stringa in 'token'.
    
    /* get the first token */
    char *token;
    token = strtok(string, " ");
       
    /* walk through other tokens */
    while( token != NULL )
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    printf("\n");
    
   
    
    // 3. Funzione strncpy -> Sudduvidere una stringa in 'token'.
    
    char str[LNGTH]= "Ciao mi chiamo Pietro.";
    char a1[LNGTH], a2[LNGTH], a3[LNGTH], a4[LNGTH];
    
    strncpy(a1, str, 4);
    strncpy(a2, &str[5], 2);
    strncpy(a3, &str[8], 6);
    strncpy(a4, &str[15], 7);
    
    printf("%s\n", a1);
    printf("%s\n", a2);
    printf("%s\n", a3);
    printf("%s\n", a4);
    
    printf("\n");
    
    
    
    // 4. Esperimento sulla funzione strtok -> Sudduvidere una stringa in 'token'.
    
    char string1[LNGTH] = "Ciao, mi chiamo GGG.";
    
    // Verifica quanti ' ' ci sono.
    int i=0, k=1;
    while (i<LNGTH)
    {
        if ( string1[i] == ' ')
        {
            k++;
        }
        i++;
    }
    
    // Salva e stampa le singole parole della stringa.
    char *token1[k];
    token1[0] = strtok(string1, " ");
    int j=0;
    while(token1[j] != NULL)
    {
        printf("%s\n", token1[j]);
        j++;
        token1[j]= strtok(NULL, " ");
    }
    
    
    
    printf("\n");
    return 0;
}
