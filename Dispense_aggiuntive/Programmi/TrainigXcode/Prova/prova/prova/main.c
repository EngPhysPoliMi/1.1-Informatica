//
//  main.c
//  prova
//
//  Created by Cendron Pietro on 29/11/20.
//
//  PRG: Verifica numero positivo.

#include <stdio.h>

int main(void){
    double num;
    printf ("Inserisci numero positivo>>");
    scanf ("%lf", &num);
    while (num<0)
    {
         printf ("Errore! \nInserisci numero positivo faccia di merda!>>");
         scanf ("%lf", &num);
    }
}
