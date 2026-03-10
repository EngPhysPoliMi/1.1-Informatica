//Esercizio 7

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

void generaMaschera(int lunghezzaStringa, int maschera []){
    for (int i=0; i<lunghezzaStringa; i++)
        maschera[i] = rand() % 2;
}

void applicaMaschera(char sorgente [], int maschera [], char destinazione[]){
    //har stringaFinale[MAX];
    int i, j;
    for (i = j = 0; i<strlen(sorgente); i++){
        if (maschera[i]){
            destinazione[j] = sorgente[i];
            j++;
        }
    }
    destinazione[j] = '\0';
}

float calcoloCompressione(char stringaOriginale [], char stringaCompressa []){
    return (strlen(stringaOriginale) - strlen(stringaCompressa))/strlen(stringaOriginale);
}

int main(){
    char stringa [MAX], stringaFiltrata[MAX];
    printf("Inserisci la stringa da comprimere attraverso maschera casuale: ");
    scanf("%s",stringa);
    int dimensioneMassima = strlen(stringa);
    int maschera [dimensioneMassima];
    generaMaschera(strlen(stringa), maschera);
    printf("\n\nHo generato la seguente maschera: ");
    for(int i=0; i<dimensioneMassima; i++)
        printf("%d ",maschera[i]);
    printf("\n\nApplicando la maschera alla linea in ingresso ottengo: ");
    applicaMaschera(stringa, maschera, stringaFiltrata);
    printf("%s\n\n", stringaFiltrata);

    return 0;
}