//
//  main.c
//  prova1
//
//  Created by Cendron Pietro on 29/11/20.
//
//  PRG: Numero quantico principale, secondario e magnetico.

#include <stdio.h>

int main(void)
{
    int num,l,m;
    printf ("n  l  m\n");
    for (num=1; num<5; ++num)
    {
        printf("%d\n", num);
        for (l=0; l<num; ++l)
        {
            switch (l)
            {
                case 0:
                    printf("   s\n");
                    break;
                case 1:
                    printf("   d\n");
                    break;
                case 2:
                    printf("   p\n");
                    break;
                case 3:
                    printf("   f\n");
                    break;
                default:
                    break;
            }
            for (m=0; m<=l; m++)
            {
                m=-m;
                printf("%7d\n",m);
                if (m!=0)
                {
                    m=-m;
                printf("%7d\n",m);
                }
            }
        }
    }
    
    return 0;
}
