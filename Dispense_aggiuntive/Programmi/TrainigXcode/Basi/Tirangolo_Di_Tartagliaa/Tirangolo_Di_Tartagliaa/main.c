//
//  main.c
//  Tirangolo_Di_Tartagliaa
//
//  Created by Cendron Pietro on 17/12/20.
//

#include <stdio.h>
#define N 100

void crea_matrice(int matrix[][2*N], int n);
void stampa_matrice(int matrix[][2*N], int n);
void stampa_matrice_senza_zeri(int matrix[][2*N], int n);
void stampa_matrice_senza_zeri_esterni(int matrix[][2*N], int n);

int main() {
    int triangolo[N][2*N];
    int n;
    
    printf("Inserisci la dimensione del triangolo >> ");
    do {
        scanf("%d", &n);
        if (n>N || n<1) {
            printf("Deve essere >=1\n");
        }
    } while (n>N || n<1);
    
    
    crea_matrice(triangolo, n);
    stampa_matrice(triangolo, n);
    printf("\n\n");
    stampa_matrice_senza_zeri(triangolo, n);
    printf("\n\n");
    stampa_matrice_senza_zeri_esterni(triangolo, n);
    
    return 0;
}

void crea_matrice(int matrix[][2*N], int n){
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<=2*(n-1); j++) {
            matrix[i][j]=0;
        }
    }
   
    matrix[0][n-1]=1;
    matrix[n-1][0]=1;
    matrix[n-1][2*(n-1)]=1;
    
    for (i=1; i<n; i++) {
        for (j=1; j<=2*(n-1); j++) {
            matrix[i][j] = matrix[i-1][j-1] + matrix[i-1][j+1];
        }
    }
}

void stampa_matrice(int matrix[][2*N], int n){
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<=2*(n-1); j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

void stampa_matrice_senza_zeri(int matrix[][2*N], int n){
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<=2*(n-1); j++) {
            if (matrix[i][j]==0) {
                printf(" ");
            } else if (matrix[i][j]!=0){
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void stampa_matrice_senza_zeri_esterni(int matrix[][2*N], int n){
    int i,j;
    int cont = 0;
    
    for (i=0; i<n; i++) {
        cont=0;
        for (j=0; j<=2*(n-1); j++) {
            if (((cont==0) || (cont>i)) && (matrix[i][j]==0)) {
                printf(" ");
            } else {
                if (matrix[i][j]!=0)
                    cont++;
                printf("%d", matrix[i][j]);
            }
        }
        printf("\n");
    }
}
