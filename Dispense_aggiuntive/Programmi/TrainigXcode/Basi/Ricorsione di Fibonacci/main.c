#include <stdio.h>
#include <stdlib.h>


//serie di Fibonacci in modo ricorsivo con una sola chiamata
//Farla in modo ricorsivo in modo che si vada ad aumentare ogni volta il numero dato dalla coppia
int fib(int term, int val, int prev);

int main()
{
    int n;
    int num;

    printf("SEQUENZA DI FIBONACCI \n");
    printf("Quale numero della sequenza ti interessa conoscere:\n> ");
    scanf("%d", &n);
    printf ("Serie di Fibonacci :");
    num = fib(n, 1, 0);
    printf ("%d", num);

    printf("\n Alla %d-esima posizione troviamo il numero : %d", n, num);
    return 0;
}


 int fib(int term, int val, int prev)
{
    if(term == 0)
        return prev;
    if(term == 1)
        return val;
    printf ("%d, ", val) ;
    return fib(term - 1, val+prev, val);
}
