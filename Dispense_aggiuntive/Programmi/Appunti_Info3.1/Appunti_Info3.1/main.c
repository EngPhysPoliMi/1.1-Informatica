//
//  main.c
//  Appunti_Info3.1
//
//  Created by Cendron Pietro on 19/10/2020.
//  Visualizzare i prossimi anni bisestili fino al 2100. Un anno è bisestile se divisibile per 4 ma non per 100, oppure se divisibile per 400.


#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int anno;

//  I modalità
/*
    int i;
    anno = 2019;

    for (i=1; i<=81; i++)
    {
        if  (((anno%100 !=0) &&(anno%4==0)) || (anno%400==0))
            printf("L'anno %d è bisestile.\n", anno);
        anno = anno + 1;
    }
*/

    
//  II modalità
/*
    for (anno=2019; anno<= 2100; anno++)
    {
        if  (((anno%100 !=0) &&(anno%4==0)) || (anno%400==0))
            printf("L'anno %d è bisestile.\n", anno);
    }
*/

    
//  III modalità
//  1. Verifico se sono su un anno bisestile.
//  2. Trovo il primo bisestile e aggiungo 4.
    anno = 2019;
    
    /*
    while (!((anno%100 !=0) &&(anno%4==0)) || (anno%400==0))
        anno++;
    printf("Il primo anno bisestile è %d.\n", anno);
    */
    
    for (anno = 2019; !( ((anno%100 !=0) && (anno%4==0)) || (anno%400==0) ); anno++);
    printf("Il primo anno bisestile è %d.\n", anno);
    
    for (anno = anno + 4; anno<=2120; anno = anno + 4)
    {
        if (anno%100!=0 || anno%400==0)
        {
            printf("L'anno %d è bisestile.\n", anno);
        }
    }

    return 0;
}
