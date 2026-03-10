//Esercizio 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Non consideriamo basi che abbiano più simboli delle 10 cifre decimali (e.g. esadecimale)

int convertiInDecimale(int numero, int basePartenza){
    int risultato = 0; 
    for (int esponente=0; numero != 0; esponente++, numero /= basePartenza ){
        risultato += (numero % 10) * pow(basePartenza, esponente);
    }
    return risultato;
}

void convertiBaseRic (int numeroInDecimale, int baseArrivo){
    if (numeroInDecimale/baseArrivo == 0) {
        printf("%d", numeroInDecimale%baseArrivo);
        return;
    }
    convertiBaseRic(numeroInDecimale/baseArrivo, baseArrivo);
    printf("%d", numeroInDecimale%baseArrivo);
}


int main(){
    int numero, basePartenza, baseArrivo;
    printf("\nInserisci il numero da convertire: ");
    scanf("%d",&numero);
    printf("\nInserisci la base nella quale si trova il numero inserito: ");
    scanf("%d",&basePartenza);
    printf("\nInserisci la base nella quale desideri convertire il numero: ");
    scanf("%d",&baseArrivo);
    printf("\nSto per convertire %d in base %d in base %d. ",numero, basePartenza, baseArrivo);
    convertiBaseRic(convertiInDecimale(numero, basePartenza), baseArrivo);
    
    printf("\n\n");

    return 0;

}