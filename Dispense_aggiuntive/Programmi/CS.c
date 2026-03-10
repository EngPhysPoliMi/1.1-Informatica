CS
..........................................................................................


//  Suddividere una stringa di caratteri (frase) in 'token' (parole).
//  Utilizzo della funzione 'strtok'.

    
    char string1[LNGTH] = "Ciao, mi chiamo GGG.";
    
    // Verifica quanti ' ' ci sono.
    int i=0, k=1;
    while (i<LNGTH)
    {
        if ( string1[i] == ' ')
        {
            k++;
        }
        i++;
    }
    
    // Salva e stampa le singole parole della stringa.
    char *token1[k];
    token1[0] = strtok(string1, " ");
    int j=0;
    while(token1[j] != NULL) 
    {
        printf("%s\n", token1[j]);
        j++;
        token1[j]= strtok(NULL, " ");
    }

..........................................................................................


//  Valutazione della possibile presenza di overflow nell'unione di due stringhe.
//  Utilizzo della funzione 'strlen' e 'strcat'.


    char s1[LNGTH] = "asasas",
         s2[LNGTH] = "asasasa";

    printf("Lunghezza I stringa: %lu\n", strlen(s1));

    if (strlen(s1)+strlen(s2) < LNGTH) {
        printf("Lunghezza I+II stringa (-> non presenta overflow): %lu\n", strlen(strcat(s1,s2)));
    } else {
        strncat(s1, s2, LNGTH - strlen(s1) -1);
        s1[LNGTH-1]='\0';
        printf("Lunghezza I+II stringa (-> presenta overflow!, dunque parte della II stringa potrebbe andare persa): %lu\n", strlen(strcat(s1,s2)));
    }


..........................................................................................


//Array

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


..........................................................................................


//  PRG: Stack with PUSH and POP functions.

#include <stdio.h>
#define LNGTH 100
#define EMPTY (-1)

int mystack[LNGTH];
int top = EMPTY;

// PUSH function.
void push ()
{
    if (top>=LNGTH-1)
    {
        printf("The array is full.");
    }
    else
    {
        int value;
        printf("Write the integer that you want to enter the array >> ");
        scanf("%d", &value);
        printf("\n");
        top++;
        mystack[top] = value;
    }
}

// POP function.
int pop ()
{
    if (top == EMPTY)
    {
        printf("The array is empty.");
    }
    int result;
    result = mystack[top];
    top--;
    return (result);
}

// Main program.
int main(void)
{
    int answer = 0;
    while (answer!=4)
    {
        printf("Possible operations that you can do on the stack:\n");
        printf("1 -> PUSH\n");
        printf("2 -> POP\n");
        printf("3 -> PEEK\n");
        printf("4 -> EXIT\n");
        printf("Choose one of the previous options >> ");
        scanf("%d", &answer);
        printf("\n");
        
        switch (answer)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("\nThe array is: ");
                for (int i=0; i<LNGTH; i++){
                    printf("%d.", mystack[i]);
                }
                printf("\n\n");
                break;
            case 4:
                break;
            default:
                printf("Wrong choice. Enter value '1', '2', '3' or '4'.\n\n");
                break;
        }
    }
    
    printf("\nThe final array is: ");
    for (int i=0; i<LNGTH; i++){
        printf("%d.", mystack[i]);
    }
    
    printf("\n\n");
    return 0;
}

..........................................................................................
