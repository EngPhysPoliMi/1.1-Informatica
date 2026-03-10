//
//  main.c
//  Lab_1.1
//
//  Created by Cendron Pietro on 23/10/2020.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    double base;
    int    esponente;
    double soluzione = 1; // La soluzione è uguale a 1 se l'esponente è uguale a 0.
    
    printf("Programma per calcolare l'elevamento a potenza E di una base B.\n");
    printf("Inserisci B ->");
    scanf("%lf", &base);
    
    do
    {
        printf("Inserisci E ->");
        scanf("%d", &esponente);
    }
    while (esponente<=0);
    
    
    for (int i=1; i<=esponente; i++)
    {
        soluzione = soluzione * base;
    }
    
    /*
    soluzione = pow(base, esponente);
    */
    
    printf("Il risultato è %.3f\n\n", soluzione);
    
    return 0;
}

 

