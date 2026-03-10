Array_3
//  main.c
//  Array
//
//  Created by Alfonso Fuggetta on 27/10/20.
//
#include <stdio.h>
void fill_array (int list[], /* output - array di n numeri interi */
                 int n, /* input - numero di elementi dell'array */
                 int in_value) /* input - valore iniziale */
{
int i; /* indice dell'array e variabile di controllo del ciclo */
for (i = 0; i < n; ++i)
    list[i] = in_value;
}
int calcolaQuadrato(int *numDaCalcolare)
{
    *numDaCalcolare = 5;
    
    return((*numDaCalcolare)*(*numDaCalcolare));
}
int main(int argc, const char * argv[]) {
    
    int vettore[10];
    int risultato;
    
    vettore[5] = 200;
    
    // risultato = vettore[5] * vettore [5];
    
    risultato = calcolaQuadrato(&vettore[5]);
    
    printf("Il quadrato di %d vale %d\n",vettore[5],risultato);
    
}
