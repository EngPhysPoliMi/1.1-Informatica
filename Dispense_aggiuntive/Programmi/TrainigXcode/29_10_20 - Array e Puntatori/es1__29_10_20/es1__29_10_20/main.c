//
//  main.c
//  es1__29_10_20
//
//  Created by Cendron Pietro on 02/12/20.
//
//  Prg: Stampa la sequenza inversa di un array di lunghezza LNGZ.

#include <stdio.h>
#define LNGZ 10

int main(void)
{
    int a[LNGZ],i;
        i=0;
    while (i<LNGZ)
    {
        printf("Fornisci un valore intero da inserire nell'array di lunghezza %d:\n", LNGZ);
        scanf("%d",&a[i]);
        i++;
    }
    printf("\n");
    i--;
    while (i>=0)
    {
        printf("%d\n", a[i]);
        i--;
    }
    return 0;
}
