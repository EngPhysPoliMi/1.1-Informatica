//Esercizio 6

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 3


void generaPrezziPerElementi(float array[]){
    for (int i=0; i<N; i++)
        array[i] = rand() % 100;
}

void generaCategoriePerElementi(int array[]){
    for (int i=0; i<N; i++)
        array[i] = rand() % 3;    
}

void generaScontiPerCategorie(int array[]){
    for (int i=0; i<M; i++)
        array[i] = rand() % 100;        
}


void calcolaArrayScontato(float arrayPrezziOriginali[], int arrayCategorieElementi[], int arrayScontiCategorie[], float arrayPrezziScontati[]){
    float scontoInEuro;
    for (int i=0; i<N; i++){
        scontoInEuro = (arrayPrezziOriginali[i] * arrayScontiCategorie[arrayCategorieElementi[i]]) / 100.0;
        arrayPrezziScontati [i] = arrayPrezziOriginali[i] - scontoInEuro;
    }
}

int main(){
    srand(time(NULL));
    float arrayPrezziElementi[N];
    int arrayCategorieElementi[N];
    int arrayScontiCategorie[M];
    float arrayPrezziScontati[N];
    generaPrezziPerElementi(arrayPrezziElementi);
    generaCategoriePerElementi(arrayCategorieElementi);
    generaScontiPerCategorie(arrayScontiCategorie);
    calcolaArrayScontato(arrayPrezziElementi, arrayCategorieElementi, arrayScontiCategorie, arrayPrezziScontati);

    for (int i = 0; i<N; i++)
        printf("\nL'elemento %d aveva prezzo %f e apparteneva alla categoria %d, che ha sconto %d, quindi ora il suo prezzo e' %f"
                , i, arrayPrezziElementi[i], arrayCategorieElementi[i], arrayScontiCategorie[arrayCategorieElementi[i]], arrayPrezziScontati[i]);

    printf("\n\n\")
    return 0;

}