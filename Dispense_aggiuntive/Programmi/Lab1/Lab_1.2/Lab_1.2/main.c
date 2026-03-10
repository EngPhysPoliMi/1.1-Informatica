//
//  main.c
//  Lab_1.2
//
//  Created by Cendron Pietro on 23/10/2020.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int limit;
    int sum = 0;
    
    do
    {
        printf("Inserisci il numero di cui vuoi calcolare la somma di tutti numeri inferiori a tale numero che siano multipli di 3 e di 5:");
        scanf("%d", &limit);
    }
    while (limit<=0);
    
    
    for (int i=1; i<limit; i++)
    {
        if (i%3==0 || i%5==0)
        {
            sum += i;
        }
    }
    
    printf("\nRisultato > %d\n\n", sum);
    return 0;
}
