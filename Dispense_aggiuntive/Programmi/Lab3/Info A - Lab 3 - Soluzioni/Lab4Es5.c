//Esercizio 5
#include <stdio.h>
#include <stdlib.h>
#define N 5


typedef struct elemento {
    int info;
    struct elemento *next;
} tipo_nodo;

typedef tipo_nodo * tipo_lista;

tipo_lista inizializzaLista(tipo_lista puntatoreAccesso){
    return NULL;
}

void visualizzaLista(tipo_lista puntatoreAccesso){
    tipo_lista p;
    for(p = puntatoreAccesso; p -> next != NULL; p = p->next)
        printf("%d ", p -> info);
}

tipo_lista inserisciElementoInCoda(tipo_lista puntatoreAccesso){
    tipo_lista p;
    int nuovaInfo;
    printf("\nChe nuovo intero vuoi inserire? ");
    scanf("%d",&nuovaInfo);
    if (puntatoreAccesso == NULL){
        puntatoreAccesso  = (tipo_lista) malloc(sizeof(tipo_nodo));
        puntatoreAccesso -> info = nuovaInfo;
        puntatoreAccesso -> next = NULL;
        printf("Inserito primo elemento");
        return puntatoreAccesso;
    }
    for (p = puntatoreAccesso; p->next!= NULL; p = p-> next);
    p -> next  = (tipo_lista) malloc(sizeof(tipo_nodo));
    p -> next -> info = nuovaInfo;
    p -> next -> next = NULL;

    return puntatoreAccesso;
}

int sommaRicorsiva (tipo_lista puntatoreAccesso){
    if (puntatoreAccesso == NULL) return 0;
    return (puntatoreAccesso -> info) + sommaRicorsiva(puntatoreAccesso -> next);
}

int main(){
    int i, s;
    tipo_lista pa;
    pa = inizializzaLista(pa);
    for (i=0; i<N; i++) pa = inserisciElementoInCoda(pa);
    printf("Visualizzo lista: ");
    visualizzaLista(pa);
    printf("\nLa somma degli elementi nella lista e': %d\n",sommaRicorsiva(pa));
    return 0;
}