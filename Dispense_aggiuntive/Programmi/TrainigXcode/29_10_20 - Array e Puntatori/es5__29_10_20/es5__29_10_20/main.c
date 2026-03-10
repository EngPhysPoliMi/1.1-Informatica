//
//  main.c
//  es5__29_10_20
//
//  Created by Cendron Pietro on 03/12/20.
//

#include <stdio.h>

int main(void)
{
    int a,b, *p, *q;
    printf("Inserici valore A:\n");
    scanf("%d", &a);
    printf("Inserici valore B:\n");
    scanf("%d", &b);
    
    /*
        p = &a;
        (*p)++;
        q = &b;
        (*q)++;
        printf("punt_A: %d\n",*p);
        printf("newA: %d\n",a);
        printf("punt_B: %d\n",*q);
        printf("newB: %d\n",b);
     
     */
    
    p = &a;
    q = &b;
    (*p)++;
    
    q = p;
    (*q)++;
    a+=2;
    
    printf("punt_A: %d\n", *p);
    printf("punt_B: %d\n", *q);
    printf("A: %d\n", a);
    printf("B: %d\n", b);
    
    return 0;
}
