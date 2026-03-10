//Esercizio 3
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


void convertiBase(int numero, int basePartenza, int baseArrivo){
    int array[255];
    int i, j;
    int numeroInDecimale = convertiInDecimale(numero, basePartenza);
    printf("In base 10, il numero e': %d",numeroInDecimale);
    for (i=0; numeroInDecimale > 0; i++, numeroInDecimale /= baseArrivo){
        printf("\nSono alla %d divisione, sto dividendo %d con %d. Il resto e' %d e la divisione %d", i,numeroInDecimale, baseArrivo, numeroInDecimale % baseArrivo, numeroInDecimale / baseArrivo);
        array[i] = numeroInDecimale % baseArrivo;
    }

    printf("\n\nRisultato conversione: ");
    for (j = i-1; j>= 0; j--)
        printf("%d",array[j]);
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
    convertiBase(numero, basePartenza, baseArrivo);
    
    printf("\n\n");

    return 0;

}