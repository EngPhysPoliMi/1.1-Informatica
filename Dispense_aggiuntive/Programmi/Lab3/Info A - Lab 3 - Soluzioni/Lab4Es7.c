//Esercizio 7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5



typedef struct elemento {
    char info;
    struct elemento *next;
} tipo_nodo;

typedef tipo_nodo * tipo_lista;

tipo_lista inizializzaLista(char stringa[], tipo_lista puntatoreAccesso){
    if (*stringa == '\0') return NULL;
    puntatoreAccesso = (tipo_lista) malloc (sizeof (tipo_nodo));
    puntatoreAccesso -> info = *stringa;
    puntatoreAccesso -> next = inizializzaLista(++stringa, puntatoreAccesso -> next);
    return puntatoreAccesso;
}

void visualizzaLista (tipo_lista puntatoreAccesso){
    if (puntatoreAccesso == NULL) return;
    printf("Elemento lista: %c\n", puntatoreAccesso->info);
    visualizzaLista(puntatoreAccesso->next);
}

int lunghezzaStringaLista (tipo_lista puntatoreAccesso){
    if (puntatoreAccesso == NULL) return 0;
    return 1+lunghezzaStringaLista(puntatoreAccesso->next);
}

int numeroVocaliStringaLista (tipo_lista puntatoreAccesso){
    if (puntatoreAccesso == NULL) return 0;
    if (puntatoreAccesso -> info == 'a' || puntatoreAccesso -> info == 'e' || puntatoreAccesso -> info == 'i' || puntatoreAccesso -> info == 'o' || puntatoreAccesso -> info == 'u' )
        return 1+numeroVocaliStringaLista(puntatoreAccesso->next);
    return numeroVocaliStringaLista(puntatoreAccesso -> next);
}

int sottostringaPresente (tipo_lista puntatoreAccesso, char sottostringa[]){
    int i;
    tipo_lista aux;
    for (i=0, aux = puntatoreAccesso; aux->next != NULL; aux = aux -> next){
        if (aux->info == sottostringa[i]){
            //flag = 1;
            i++;
            if (sottostringa[i] == '\0') return 1;
        }else{
            //flag = 0;
            i = 0;
        }
    }
    return 0;
}

tipo_lista inserisciInPosizioneN(tipo_lista puntatoreAccesso, char sottostringa[], int n){
    tipo_lista aux, aux2;
    if (puntatoreAccesso == NULL && n != 0){
        printf("NON VALIDO");
        return puntatoreAccesso;
    }
    int i,j;
    for (i=0, aux = puntatoreAccesso; aux != NULL && i!= n-1; aux = aux->next, i++);
    if (i!=n-1){
        printf("NON VALIDO");
        return puntatoreAccesso;
    }
    for (j=strlen(sottostringa)-1; j>=0; j--){
        aux2 = aux -> next;
        aux -> next = (tipo_lista) malloc (sizeof(tipo_nodo));
        aux -> next -> info = sottostringa[j];
        aux -> next -> next = aux2;
    }
    return puntatoreAccesso;
}

int main(){
    char stringa[255], sottostringa[255], nuovaParola[255];
    int pos;
    tipo_lista stringaLista;
    printf("Inserisci una stringa: ");
    scanf("%s",stringa);
    stringaLista = inizializzaLista(stringa, stringaLista);
    visualizzaLista(stringaLista);
    printf("La lunghezza della stringa-lista e': %d\n", lunghezzaStringaLista(stringaLista));
    printf("Il numero di vocali e': %d\n", numeroVocaliStringaLista(stringaLista));
    printf("Inserisci una sottostringa da cercare nella stringa lista: ");
    scanf("%s",sottostringa);
    if (sottostringaPresente(stringaLista, sottostringa))
        printf("\nLa sottostringa e' presente nella stringa-lista\n");
    else
        printf("\nLa sottostringa non e' presente nella stringa-lista\n");
    printf("\nInserisci una parola da inserire nella stringa-lista: ");
    scanf("%s", nuovaParola);
    printf("\nInserisci la posizione dove vuoi inserirla: ");
    scanf("%d", &pos);
    stringaLista = inserisciInPosizioneN (stringaLista, nuovaParola, pos);
    printf("\nStampo la nuova stringa-lista\n");
    visualizzaLista(stringaLista);
    return 0;
}