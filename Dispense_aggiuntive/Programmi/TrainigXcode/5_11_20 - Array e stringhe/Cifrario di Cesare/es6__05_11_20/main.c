//
//  main.c
//  es6__05_11_20
//
//  Created by Cendron Pietro on 17/12/20.
//
//  PRG: cifrario di Cesare.
//  chiave a --> a b c d e f g h i ...
//  chiave b --> _ a b c d e f g h ...
//  chiave c --> _ _ a b c d e f g ...

#include <stdio.h>
#include <string.h>
#define N 300

void cifrario_cesare(unsigned char string[], char start_key, char key);
void calcola_chiavi(char key, char *keyMai, char *keyMin);
char decifra(unsigned char string[]);

int main() {
    unsigned char str[N];
    char cx;
    
    printf("Inserisci il messaggio da cifrare >>\n");
    fpurge(stdin);
    scanf("%[^\n]s", str);
    
    printf("Inserisci la chiave di codifica >> ");
    scanf(" %c", &cx);
    
    cifrario_cesare(str, 'a', cx);
    printf("Il messaggio cifrato è >> %s\n", str);
    
    
    printf("\nLa chiave di decodifica è >> %c\n\n", decifra(str));
    //cifrario_cesare(str, cx, 'a');
    //printf("Il messaggio cifrato è >> %s\n", str);
    
    return 0;
}

void cifrario_cesare(unsigned char string[], char start_key, char key)
{
    int i;
    char keyMai=0, keyMin=0;
    char start_keyMin = 0, start_keyMai = 0;
    
    calcola_chiavi(key, &keyMai, &keyMin);
    calcola_chiavi(key, &start_keyMai, &start_keyMin);
    
    
    if ((start_key>='a')&&(start_key<='z')) {
        start_keyMin = start_key;
        start_keyMai = start_key - 'a' + 'A';
    } else if ((start_key>='A')&&(start_key<='Z')) {
        start_keyMin = start_key + 'a' - 'A';
        start_keyMai = start_key;
    }
    
    for (i=0; string[i]!='\0'; i++) {
        if ((string[i]>='a')&&(string[i]<='z')) {
            
            //minuscole
            string[i] = string[i] - start_keyMin + keyMin;
            if (string[i]>'z') {
                string[i] = string[i] - 'z' +'a' -1;
            }
            if (string[i]<'a') {
                string[i] = string[i] - 'a' +'z' +1;
            }
        
        } else if ((string[i]>='A')&&(string[i]<='Z')) {
           
            //maiuscole
            string[i] = string[i] - start_keyMai + keyMai;
            if (string[i]>'Z') {
                string[i] = string[i] - 'Z' +'A' -1;
            }
            if (string[i]<'A') {
                string[i] = string[i] - 'A' +'Z' +1;
            }
        }
    }
}

void calcola_chiavi(char key, char *keyMai, char *keyMin)
{
    if ((key>='a')&&(key<='z')) {
        *keyMin = key;
        *keyMai = key - 'a' + 'A';
    } else if ((key>='A')&&(key<='Z')) {
        *keyMin = key + 'a' - 'A';
        *keyMai = key;
    }
}

char decifra(unsigned char string[])
{
    char i,j;
    unsigned char string2[N];
    char stop = 'n' ;
    
    for (i='a'; (i<='z') && (stop=='n'); i++) {
        for (j=0; string[j] != '\0'; j++) {
            string2[j] = string[j];
        }
        string2[j] = '\0';
        
        cifrario_cesare(string2, 'a', i);
        printf("La decodifica %s è giusta (s/n)?", string2);
        scanf(" %c", &stop);
    }
    return i-1;
}
