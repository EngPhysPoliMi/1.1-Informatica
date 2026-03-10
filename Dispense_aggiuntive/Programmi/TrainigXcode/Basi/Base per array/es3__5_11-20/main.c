//
//  main.c
//  es3__5_11-20
//
//  Created by Cendron Pietro on 11/12/20.
//
//  PRG: Base per creazione di un array a[lenght].

#include <stdio.h>

int main(void)
{
    int lenght;
    printf("Numero di elementi dell'array >> ");
    scanf("%d", &lenght);
    
    int a[lenght];
    printf("\nFornisci un valore da inserire nell'array di lunghezza %d >> ", lenght);
    int i=0;
    while (i<lenght){
        scanf("%d",&a[i]);
        i++;
    }
    printf("\nL'array inserito è il seguente: ");
    for (i=0; i<lenght; i++){
        printf("%d.", a[i]);
    }

    printf("\n");
    
    return 0;
}
