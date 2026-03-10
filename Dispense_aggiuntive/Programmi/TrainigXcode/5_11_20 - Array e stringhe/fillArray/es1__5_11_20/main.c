//
//  main.c
//  es1__5_11_20
//
//  Created by Cendron Pietro on 10/12/20.
//
//  PRG: Crea un array di n elementi che valgono tutti 1, con l'utilizza di un sottoprogramma.

#include <stdio.h>

void fillArray(int list[],    //array
               int n,         //numero di elementi
               int in_value   //valore degli elementi dell'array
               );

int main ()
{
    int var1;
    printf("Numero di elementi dell'array >> ");
    scanf("%d", &var1);
    
    int arr[var1], element;
    
    printf("\n\nL'array è il seguente>> ");
    for (int j=0; j<var1; j++)
    {
        fillArray (&arr[j], var1, element = 1);
        printf("%d ", arr[j]);
    }
    printf("\n");
    
    
    return 0;
}

void
fillArray(int list[], int n, int in_value)
{
    for (int i=0; i<n; i++)
    {
        list[i] = in_value;
    }
}

