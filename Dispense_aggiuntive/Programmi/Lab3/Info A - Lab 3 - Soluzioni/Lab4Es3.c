//Creare una funzione ricorsiva che restituisca 1 se un numero passato per parametro è presente in un array di interi, 0 altrimenti.

#include <stdio.h>
#include <stdlib.h>


int presente(int array[], int dim, int numero){
    if (dim == 0) return 0;
    if (array[0] == numero) return 1;
    return presente(++array, --dim, numero);
}

int main(){
    int vettore[5] = {1,2,3,4,5};
    int numeroDaCercare = 3;
    if (presente(vettore, 5, numeroDaCercare))
        printf("\nIl numero %d si trova nell'array.\n", numeroDaCercare);
    else
        printf("\nIl numero %d NON si trova nell'array.\n", numeroDaCercare);

    return 0;

}
