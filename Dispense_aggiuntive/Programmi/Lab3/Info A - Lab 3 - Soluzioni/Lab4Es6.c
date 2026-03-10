#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct elemento {
	char nome[10];
	char cognome[10];
	int annoNascita;
	int mediaEsami;
	struct elemento *next;
} tipo_nodo;

typedef tipo_nodo * tipo_lista;

tipo_lista inizializzaLista(){
	return NULL;
}

void visualizzaLista(tipo_lista puntatoreAccesso){
	tipo_lista p;
	if (puntatoreAccesso == NULL){
		printf("Lista vuota\n");
		return;
	}
	int contatore;
	for (p = puntatoreAccesso, contatore = 0; p != NULL; p = p->next, contatore++){
		printf("Alunno %d\n\n", contatore);
		printf("Nome: %s\n", p->nome);
		printf("Cognome: %s\n", p->cognome);
		printf("Anno di nascita: %d\n", p->annoNascita);
		printf("Nome: %d\n", p->annoNascita);
		printf("Media esami: %d\n", p->mediaEsami);
		printf("\n");
	}
}

tipo_lista inserisciInTesta(tipo_lista puntatoreAccesso){
	tipo_lista nuovoNodo = (tipo_lista)malloc(sizeof(tipo_nodo));
	printf("Inserire il nome dello studente: ");
	scanf("%s", nuovoNodo->nome);
	printf("Inserire il cognome dello studente: ");
	scanf("%s", nuovoNodo->cognome);
	printf("Inserire l'anno di nascita dello studente: ");
	scanf("%d", &(nuovoNodo->annoNascita));
	printf("Inserire la media degli esami dello studente: ");
	scanf("%d", &(nuovoNodo->mediaEsami));
	nuovoNodo->next = puntatoreAccesso;
	return nuovoNodo; //nuovoNodo diventa il nuovo puntatore di accesso alla lista
}

tipo_lista inserisciInCoda(tipo_lista p){
	if (p == NULL) return inserisciInTesta(p);
	if (p->next == NULL)
		p->next = inserisciInTesta(p->next);
	else
		inserisciInCoda(p->next);
	return p;
}


tipo_lista inserisciInPosizioneN(tipo_lista puntatoreAccesso, int n){
	tipo_lista aux, aux2;
	if (puntatoreAccesso == NULL && n != 0){
		printf("NON VALIDO");
		return puntatoreAccesso;
	}
	int i;
	for (i = 0, aux = puntatoreAccesso; aux != NULL; aux = aux->next, i++){
		if (i == n - 1){
			aux2 = aux->next;
			aux->next = (tipo_lista)malloc(sizeof(tipo_nodo));
			printf("Inserire il nome dello studente: ");
			scanf("%s", aux->next->nome);
			printf("Inserire il cognome dello studente: ");
			scanf("%s", aux->next->cognome);
			printf("Inserire l'anno di nascita dello studente: ");
			scanf("%d", &(aux->next->annoNascita));
			printf("Inserire la media degli esami dello studente: ");
			scanf("%d", &(aux->next->mediaEsami));
			aux->next->next = aux2;
		}
	}
	return puntatoreAccesso;
}



/* funzione per scambiare i valori di due elementi*/
void swap(tipo_lista a, tipo_lista b)
{
	tipo_nodo aTemp = *a;
	tipo_lista aNext = a->next;
	tipo_lista bNext = b->next;

	*a = *b;
	*b = aTemp;
	b->next = bNext;
	a->next = aNext;
}

/* Bubble sort decrescente*/
tipo_lista ordinaListaPerVoto_bubbleSort(tipo_lista puntatoreAccesso)
{
	int numeroScambi;
	tipo_lista aux;
	tipo_lista aux2 = NULL;

	if (puntatoreAccesso == NULL)
		return NULL;

	do
	{
		numeroScambi = 0;
		aux = puntatoreAccesso;

		while (aux != NULL && aux->next != aux2)
		{
			if (aux->mediaEsami < aux->next->mediaEsami)
			{
				swap(aux, aux->next);
				numeroScambi = 1;
			}
			aux = aux->next;
		}
		aux2 = aux;
	} while (numeroScambi);

	return puntatoreAccesso;
}


void studentiDel1992(tipo_lista puntatoreAccesso){
	if (puntatoreAccesso == NULL) return;
	if (puntatoreAccesso->annoNascita == 1992)
		printf("%s %s\n", puntatoreAccesso->nome, puntatoreAccesso->cognome);
	studentiDel1992(puntatoreAccesso->next);
}


int main(){
	tipo_lista puntatoreAccesso;
	puntatoreAccesso = inizializzaLista();
	int scelta, n;
	do{
		printf("1. Visualizza lista studenti\n");
		printf("2. Inserisci uno studente in testa\n");
		printf("3. Inserisci uno studente in coda\n");
		printf("4. Inserisci uno studente in posizione arbitraria\n");
		printf("5. Ordina la lista in base al voto\n");
		printf("6. Studenti del 1992\n");
		printf("7. Esci");
		printf("\n\nInserisci scelta: ");
		scanf("%d", &scelta);
		switch (scelta){
		case 1: visualizzaLista(puntatoreAccesso);
			break;
		case 2: puntatoreAccesso = inserisciInTesta(puntatoreAccesso);
			break;
		case 3: puntatoreAccesso = inserisciInCoda(puntatoreAccesso);
			break;
		case 4:{
            printf("\nInserisci posizione: ");
            scanf("%d", &n);
            puntatoreAccesso = inserisciInPosizioneN(puntatoreAccesso, n);
		}
			break;
		case 5: puntatoreAccesso = ordinaListaPerVoto_bubbleSort(puntatoreAccesso);
			break;
		case 6: studentiDel1992(puntatoreAccesso);
			break;
		case 7: break;
		default: printf("\nScelta errata, provare a reinserirla\n");
		}
	} while (scelta != 7);

	return 0;
}