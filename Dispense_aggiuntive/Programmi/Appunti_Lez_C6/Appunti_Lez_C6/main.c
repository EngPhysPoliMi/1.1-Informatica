//
//  main.c
//  Appunti_Lez_C6
//
//  Created by Cendron Pietro on 21/10/2020.
//

#include <stdio.h>

void assegna_val(int a_sottoprg)
{
    a_sottoprg = 98765;
}

void assegna_punt(int *a_sottoprg)
{
    *a_sottoprg = 10;
}


int main(int argc, const char * argv[])
{
    int a_main;
    
    a_main = 50;
    
    
    // Chiamo per valore
    
    assegna_val(a_main);
    
    printf("Il valore della variabile è %d\n", a_main);
    
   
    
    // Chiama per indirizzo
    
    assegna_punt(&a_main);
    
    printf("Il valore della variabile è %d\n", a_main);
    
}




/*
#include <stdio.h>
void assegna_val(int a_sottoprogramma)
{
    a_sottoprogramma = 10;
    
    a_sottoprogramma;
}
void assegna_punt(int *a_sottoprogramma)
{
    *a_sottoprogramma = 10;
}
int main(int argc, const char * argv[]) {
    int a_main;
    
    a_main = 50;
    
    // chiamo per valore
    
    assegna_punt(&a_main);
    
    printf("Il valore della variabile è %d\n",a_main);
    
    // chiamo per indirizzo
    
    a_main = 30;
    
    assegna_val(a_main);
    
    printf("Il valore della variabile è %d\n",a_main);
}
*/
