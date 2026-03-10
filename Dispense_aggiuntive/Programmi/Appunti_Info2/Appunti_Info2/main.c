//
//  main.c
//  Appunti_Info2
//
//  Created by Cendron Pietro on 12/10/2020.
/*
    1. Dare instruzioni all'utente
    2. Leggere i due dati che descrivono l'utente
    3. Calcolo BMI
    4. Identificare il range a cui appartiene il BMI calcolato
    5. Stampare il risultato
*/

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[])
{
    double wt_kg, //peso in kilogrammi
           ht_m,  //altezza in metri
           BMI;   //Body Mass Index
   
    char   type;  // T, N, P, O
    // Passo 1
    printf("Questo programma calcola il BMI.\n");
    printf("Per poterlo calcolare dovrai inserire il tuo peso in kg e la tua altezza in metri.\n");
    
    // Passo 2
    printf("Inserisci peso>");
    scanf("%lf", &wt_kg);
    printf("Inserisci altezza>");
    scanf("%lf", &ht_m);
    
    // Passo 3
    BMI = wt_kg / (ht_m * ht_m);
    
    // Passo 4
    if (BMI<=18.5)
    {
        type = 'T';
    }
    else
    {
        if (BMI>=18.5 && BMI<24.9)
        {
            type = 'P';
        }
        else
        {  if (BMI>=24.9 && BMI<29.9)
           {
               type = 'N';
           }
           else
           {
               type = 'O';
           }
        }
    }
    
    // Passo 5
    printf("\nIl tuo BMI è %f.", BMI);
    printf("\nLa tipologia è %c.\n\n", type);
    
    return 0;
}
