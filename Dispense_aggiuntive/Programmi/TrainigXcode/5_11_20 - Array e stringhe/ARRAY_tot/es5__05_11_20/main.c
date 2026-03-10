//
//  main.c
//  es5__05_11_20
//
//  Created by Cendron Pietro on 16/12/20.
//
//  PRG: 1. Riempire un array data una lunghezza.
//       2. Stampa l'array.
//       3. Bubblesort -> Ordinamento di un array.
//       4. Binary search -> ricerca di un elemento all'interno di un array.

#include <stdio.h>
#include <ctype.h>
#define LNGTH 100


int riempi_array(int vettore[]);
void riempi_array1(int vettore[], int *length);
void riempi_array2(int vettore[], int *length);
void stampa_array(int vettore[], int length);
void stampa_array_contrario(int vettore[], int length);
void bubblesort(int vettore[], int length);
int binary_search(int vettore[], int length, int x);

int main()
{
    int a[LNGTH];
    int L = 0;
    char command;
    int y;
    int pos_num;
    
    do{
        printf("Possible options:");
        printf("\na) Inserisci l'array");
        printf("\nb) Stampa l'array");
        printf("\nc) Ordina l'array");
        printf("\nd) Cerca elemento nell'array");
        printf("\ne) Esci\n");
        
        do {
            scanf("%c",&command);
            if ((command<'a')||(command>'e')) {
                printf("Comando non valido. ");
                scanf("%c",&command);
            }
        } while ((command<'a')||(command>'e'));

        
        switch (command) {
            case 'a':
                L = riempi_array(a);
                //riempi_array1(a, &L);
                //riempi_array2(a, &L);
                break;
            case 'b':
                stampa_array(a, L);
                //stampa_array_contrario(a, L);
                break;
            case 'c':
                bubblesort(a, L);
                break;
            case 'd':
                printf("Inserisci l'intero da ricercare >> ");
                scanf("%d", &y);
                pos_num = binary_search(a, L, y);
                if (pos_num != -1) {
                    printf("Il numero è stato trovato in posizione %d, infatti: array[%d] = %d.\n", pos_num, pos_num, a[pos_num]);
                } else {
                    printf("Posizione numero non trovata.\n");
                }
                break;
            default:
                break;
        }
    } while (command != 'e');
    
    return 0;
}

//__________________________________________________

int riempi_array(int vettore[])
{
    int l;
    printf("Quanti valori vuoi inserire nell'array? >> ");
    scanf("%d", &l);
    for (int i=0; i<l; i++) {
        scanf("%d", &vettore[i]);
    }

    return (l);
}

//__________________________________________________

void riempi_array1(int vettore[], int *length)
{
    printf("Quanti valori vuoi inserire nell'array? >> ");
    scanf("%d", length);
    for (int i=0; i<*length; i++) {
        scanf("%d", &vettore[i]);
    }
}

//__________________________________________________

void riempi_array2(int vettore[], int *length)
{
    printf("Quanti valori vuoi inserire nell'array? >> ");
    scanf("%d", length);
    for (int i=0; i<*length; i++) {
        scanf("%d", vettore+i);
    }
}

//__________________________________________________

void stampa_array(int vettore[], int length){
    for (int i=0; i<length; i++) {
        printf("%d", vettore[i]);
    }
}

//__________________________________________________

void stampa_array_contrario(int vettore[], int length){
    for (int i=length-1; i>=0; i--) {
        printf("%d", vettore[i]);
    }
}

//__________________________________________________

void bubblesort(int vettore[], int length){
    for (int i=0; i<length-1; i++)
    {
        if (vettore[i]>vettore[i+1])
        {
            int temp;
            temp = vettore[i];
            vettore[i] = vettore[i+1];
            vettore[i+1] = temp;
            i = -1;
        }
    }
}

//__________________________________________________

int binary_search(int vettore[], int length, int x){
    int inizio=0,
        medio,
        fine=length-1;
    
    // Non so se l'array è ordinato e quindi lo ordino.
    bubblesort(vettore, length);
    
    // Ora il mio vettore è ordinato.
    while (inizio<=fine) {
        medio = inizio + (fine-inizio)/2;
        if (vettore[medio]==x) {
            return medio;
        } else if (vettore[medio]<x) {
            inizio = medio+1;
        } else {
            fine = medio+1;
        }
    }
    return -1;
}
