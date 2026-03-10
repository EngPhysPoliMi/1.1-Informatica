//
//  main.c
//  es2__29_10_20
//
//  Created by Cendron Pietro on 02/12/20.
//
//  Prg: Creazione di un istogramma orizzontale definito dall'array di lunghezza LNGZ.

#include <stdio.h>
#define LNGZ 5

int main(void)
{
    int  i, a[LNGZ], j;
    
    i=0;
    while (i<LNGZ)
    {
        printf("Fornisci un valore intero da inserire nell'array di lunghezza %d:\n", LNGZ);
        scanf("%d",&a[i]);
        i++;
    }
    
    printf("\n\n%10s%10s%13s\n","Elem_Array","Val_Arr","Hisogram");
    i=0;
    j=0;
    while (i<LNGZ)
    {
        printf("%10d%10d%4s", i, a[i], " ");
        while (j<a[i])
        {
            printf("*");
            j++;
        }
        printf("\n");
        j=0;
        i++;
    }
    
    return 0;
}
