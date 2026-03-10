//Creare una funzione ricorsiva che restituisca 1 se un array di interi è ordinato in maniera crescente, 0 altrimenti.

#include <stdio.h>
#include <stdlib.h>

int ordine(int array[], int dim){
    if (dim < 2) return 0;
    if (dim == 2) return (array[0] < array [1]);
    return (array[0] < array [1]) && ordine(++array, --dim);
    //Note:
    //che cosa significa "return (array[0] < array [1])"? 
    //Questa è un'operazione logica, che può avere come risultato "Vero" o "Falso"
    //Per questo utilizziamo poi l'and logico (&&) con gli elementi successivi (la condizione finale sarà vera se lo sono tutte)
    //In C però non esiste il tipo "Vero"/"Falso" (che altri linguaggi chiamano "boolean"), per questo vengono usati gli interi
    //E il "Vero" viene codificato come 1, mentre il "Falso" come 0    
}



int main(){
    int vettore[5] = {1,2,3,4,5};
    if (ordine(vettore, 5))     //Notate qui l'assenza di un "== 1" (che funzionerebbe lo stesso). L'if può cercare in automatico il valore logico "Vero" restituito da una funzione
        printf("\nL'array e' ordinato in maniera crescente.\n");
    else
        printf("\nL'array NON e' ordinato in maniera crescente.\n");

    return 0;
}


