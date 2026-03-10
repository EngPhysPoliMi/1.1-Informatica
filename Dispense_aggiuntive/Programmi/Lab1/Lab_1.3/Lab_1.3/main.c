//
//  main.c
//  Lab_1.3
//
//  Created by Cendron Pietro on 23/10/2020.
//

    
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

int main(void)
{
    int a, b, mcm;
    printf("Questo programma acquisisce due interi positivi 'a' e 'b' e ne calcola il loro mcm.");
    printf("Inserisci due numeri separati dallo spazio:");
    scanf("%d", &a);
    scanf("%d", &b);
    
    mcm = a*b;
    
    for (int i=mcm; i>1; i--)
    {
        if (i%a==0 && i%b==0)
        {
            mcm = i;
        }
    }
    
    printf("mcm = %d\n", mcm);
    
}

