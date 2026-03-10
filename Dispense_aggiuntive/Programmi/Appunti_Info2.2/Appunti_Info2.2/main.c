//
//  main.c
//  Appunti_Info2.2
//
//  Created by Cendron Pietro on 12/10/2020.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    char codiceGas;

    
    printf("Mi dici il colore del gas?\n");
    scanf("%c", &codiceGas);
    
    switch (codiceGas)
    {
        case 'A':
        case 'a':
            printf("Ammoniaca\n");
            break;
        case 'M':
        case 'm':
            printf("Monossido di carbonio\n");
            break;
        case 'I':
        case 'i':
            printf("Idrogeno\n");
            break;
        case 'O':
        case 'o':
            printf("Ossigeno\n");
            break;
        default:
            printf("Errore, non accettabile.\n");
            break;
            
    }

    return 0;
}
