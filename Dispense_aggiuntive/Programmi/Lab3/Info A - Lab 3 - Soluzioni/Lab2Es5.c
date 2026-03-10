//Esercizio 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toUpperCase(char stringa[]){
    for(int i=0; i<strlen(stringa); i++){
        if (stringa[i] >= 'a' && stringa[i] <= 'z' ) 
            stringa[i] += 'A' - 'a';
    }
}

void invertCase(char stringa[]){
    for(int i=0; i<strlen(stringa); i++){
        if (stringa[i] >= 'a' && stringa[i] <= 'z' ) 
            stringa[i] += 'A' - 'a';
        else if (stringa[i] > 'A' && stringa[i] < 'Z' ) 
            stringa[i] -= 'A' - 'a';
    }
}

//Questa è una funzione non richiesta, ma che mi tornerà utile nella conversione tra camel e snake case
//Restituisce 1 se sia c1 che c2 sono entrambi in maiuscolo o in minuscolo
//Altrimenti 0
int matchCase(char c1, char c2){
    if ((c1 > 'a' && c1 < 'z') && (c2 > 'a' && c2 < 'z')) return 1; //entrambi minuscole
    if ((c1 > 'A' && c1 < 'Z') && (c2 > 'A' && c2 < 'Z')) return 1; //entrambi maiuscole
    return 0;
}

int seSuccessivoMaiuscolo(char c1, char c2){
    if ((c1 >= 'a' && c1 <= 'z') && (c2 >= 'A' && c2 <= 'Z')) return 1; //c2 è maiuscolo, c1 no
    return 0;
}

void camelToSnake (char stringa[]){
    //Siamo furbi! Non è richiesto se restituire o visualizzare la stringa. Qual è la strada più veloce?
    //Il visualizzare:
    for (int i=0; stringa[i] != '\0' ; i++){
        if (seSuccessivoMaiuscolo(stringa[i], stringa[i+1])) printf("%c_",stringa[i]);
        else printf("%c",stringa[i]);
    }
}

int main(){
    char stringa1 [255] = "HelloWorld";
    char stringa2 [255] = "CiaoMondo";
    char stringa3 [255] = "StringaInCamel";
    printf("\nIn uppercase la stringa %s diventa: ", stringa1);
    toUpperCase(stringa1);
    printf("%s",stringa1);
    printf("\nIn invertcase la stringa %s diventa: ", stringa2);
    invertCase(stringa2);
    printf("%s",stringa2);
    printf("\nIn snake case la stringa %s diventa: ", stringa3);
    camelToSnake(stringa3);

    printf("\n\n");
}