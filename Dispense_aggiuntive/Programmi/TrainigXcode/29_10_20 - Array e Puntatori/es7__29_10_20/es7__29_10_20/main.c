//
//  main.c
//  es7__29_10_20
//
//  Created by Cendron Pietro on 03/12/20.
//
// Prg: ordina i valori di un array.

#include <stdio.h>

int main(void)
{
    int a[]={64, 32, 8, 16, 2, 128, 4, 1},
        length;
    
    length = sizeof(a)/sizeof(a[0]);
    printf("%d\n", length);
    
    int swap;
    for (int i=0; i<length; i++)
    {
        swap = 1;
        for (int j=0; j<length-1; j++)
        {
            if (a[j]>a[j+1])
            {
                int temp;
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                swap = 0;
            }
        }
        if (swap == 1)
            break;
    }
    
    
    /*
         Altro modo per svolgere il ciclo:
     
         for (int j=0; j<length-1; j++)
         {
             if (a[j]>a[j+1])
             {
                 int temp;
                 temp = a[j];
                 a[j] = a[j+1];
                 a[j+1] = temp;
                 j = -1;
             }
         }
     
     */
    
    /*
         Altro modo per svolgere il ciclo:
     
         int swap=0;
         for (int i=0; (i<length) && (swap==0); i++)
         {
             swap = 1;
             for (int j=0; j<length-1; j++)
             {
                 if (a[j]>a[j+1])
                 {
                     int temp;
                     temp = a[j];
                     a[j] = a[j+1];
                     a[j+1] = temp;
                    swap==0
                 }
             }
         }
     
     */
    
    for (int i=0; i<length; i++)
    {
        printf("%d ", a[i]);
    }
    
    printf("\n");
    
    return 0;
}
