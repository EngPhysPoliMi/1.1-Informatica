//Esercizio 8

#include <stdio.h>
#include <stdlib.h>
#define DIM 22

void mergeArray(int array_in [], char * str){
    char * aux;
    int * i; 
    for(i=array_in, aux=str; i<array_in + DIM; i++, aux++){
        *aux = *i;
    }
}

int main(){
    int array_in[DIM] = {67, 79, 77, 80, 76, 73, 77, 69, 78, 84, 73, 33, 72, 97, 105, 70, 105, 110, 105, 116, 111, 33};
    char stringa[DIM];
    mergeArray(array_in, stringa);
    printf("La stringa generata è %s\n\n", stringa);
    return 0;
}