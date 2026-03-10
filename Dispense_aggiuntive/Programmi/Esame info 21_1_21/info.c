
A    B    C    OUT
0    0    0    0
0    0    1    1
0    1    0    1
0    1    1    1
1    0    0    1
1    0    1    1
1    1    0    1
1    1    1    1
......................................................

Scrivere il codice Matlab che restituisca i valori richiesti.
Attenersi al numero massimo di righe di codice indicato.

1. Creare una matrice quadrata A di dimensione casuale tra 3 e 10 contenente solo numeri 7 (1 riga - 1 punto)

A = (7, randi[3 10])

2. Sommare alle colonne pari nuemri casuali tra 1 e 5.  (1 riga - 1 punto)
A(:,2:2:end)= A(:2:2:end) + randi([1 5])

3. Calcolare la media totale della matrice   (1 riga - 1 punto)
mean(mean(A))

4. Eliminare le righe della matrice A la cui somma delle componenti è minore di 10.  (1 riga - 2 punti)
A(sum(A,2)<10, :)=[]


5. Scrivere una funzione Matlab che presa in ingresso la matrice, restituisca la matrice contenente solo
 i valori delle diagonali; gli altri valori vengono posti a zero. (2 punti). Testo su più righe.

 function B = funzioneDiagonali(A)
     diag(diag(A))
 end
