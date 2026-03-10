//
//  main.c
//  es4__05_11_20
//
//  Created by Cendron Pietro on 15/12/20.
//
//  PRG: Valutazione della possibile presenza di overflow nell'unione di due stringhe.
//       Utilizzo della funzione 'strlen' e 'strcat'.

#include <stdio.h>
#include <string.h>
#define LNGTH 20

int main()
{
    char s1[LNGTH] = "asasas",
         s2[LNGTH] = "asasasa";
    
    printf("Lunghezza I stringa: %lu\n", strlen(s1));
    printf("Lunghezza II stringa: %lu\n", strlen(s2));
    
    if (strlen(s1)+strlen(s2) < LNGTH) {
        printf("Lunghezza I+II stringa (-> non presenta overflow): %lu\n", strlen(strcat(s1,s2)));
    } else {
        strncat(s1, s2, LNGTH - strlen(s1) -1);
        s1[LNGTH-1]='\0';
        printf("Lunghezza I+II stringa (-> presenta overflow!, dunque parte della II stringa potrebbe andare persa): %lu\n", strlen(strcat(s1,s2)));
    }
    
    return 0;
}
