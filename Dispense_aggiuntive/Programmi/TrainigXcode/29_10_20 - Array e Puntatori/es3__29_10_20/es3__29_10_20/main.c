//
//  main.c
//  es3__29_10_20
//
//  Created by Cendron Pietro on 02/12/20.
//
//
//  Prg: Creazione di un istogramma orizzontale definito dall'array di lunghezza LNGZ.

#include <stdio.h>
#define LNGZ 5

int main(void)
{
    int  i, a[LNGZ], max, j;
    
    i=0;
    while (i<LNGZ)
    {
        printf("Fornisci un valore intero da inserire nell'array di lunghezza %d:\n", LNGZ);
        scanf("%d",&a[i]);
        i++;
    }
    
    //CALCOLO VALORE MASSIMO
    max=a[0];
    for (i=1; i<LNGZ; i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
    }
    
    //DISEGNO ISTOGRAMMA
    for (i=max; i>=1; i--)
    {
        printf("%10s", " ");
        for (j=0; j<LNGZ; j++)
        {
            if (a[j]>=i)
            {
                printf("%6s*", " ");
            } else {
                printf("%7s", " ");
            }
        }
        printf("\n");
        
    }
    
    //LEGENDA
    printf("\nVal_Array ");
    for (i=0; i<LNGZ; i++)
    {
        printf("%7d", a[i]);
    }
    printf("\nElem_Array");
    for (i=0; i<LNGZ; i++)
    {
        printf("%7d", i);
    }
    printf("\n\n");
    
    return (0);
}
