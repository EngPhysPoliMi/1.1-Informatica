//Restituire la somma di un array di interi in maniera ricorsiva

#include <stdio.h>
#include <stdlib.h>

int somma (int array [], int dim){
    if (dim == 0) return 0;
    return array[0] + somma(++array, --dim);
    //Piccole note: 
    //1. l'else non è necessario, perché la return è un'istruzione che termina tutta la funzione
    //2. Nella ricorsione, utilizziamo sempre il preincremento invece che il postincremento (++array e non array++), in 
    //modo da essere sicuri che l'operazione di incremento venga fatta prima della chiamata ricorsiva della funzione
}


int main(){
    int vettore[5] = {1,2,3,4,5};
    printf("La sommma dell'array e': %d",somma(vettore, 5));
}
