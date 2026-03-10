//
//  main.c
//  Calcolatore cash
//
//  Created by Cendron Pietro on 09/10/2020.
//

#include <stdio.h>
#include <math.h>

int
main(void)
{
    int   n_cent_10,
          n_cent_20,
          n_cent_50,
          n_euro_1,
          n_euro_2,
          n_euro_5,
          n_euro_10,
          n_euro_20,
          n_euro_50,
          n_euro_100,
          n_euro_200,
          n_euro_500;
    
    double cash_tot;
    
    printf("Number of 10 cents >");
    scanf("%d", &n_cent_10);
    printf("Number of 20 cents >");
    scanf("%d", &n_cent_20);
    printf("Number of 50 cents >");
    scanf("%d", &n_cent_50);
    printf("Number of 1 euro >");
    scanf("%d", &n_euro_1);
    printf("Number of 2 euro >");
    scanf("%d", &n_euro_2);
    printf("Number of 5 euro >");
    scanf("%d", &n_euro_5);
    printf("Number of 10 euro >");
    scanf("%d", &n_euro_10);
    printf("Number of 20 euro >");
    scanf("%d", &n_euro_20);
    printf("Number of 50 euro >");
    scanf("%d", &n_euro_50);
    printf("Number of 100 euro >");
    scanf("%d", &n_euro_100);
    printf("Number of 200 euro >");
    scanf("%d", &n_euro_200);
    printf("Number of 500 euro >");
    scanf("%d", &n_euro_500);
    
    cash_tot = n_cent_10  * 0.10 +
               n_cent_20  * 0.20 +
               n_cent_50  * 0.50 +
               n_euro_1   * 1    +
               n_euro_2   * 2    +
               n_euro_5   * 5    +
               n_euro_10  * 10   +
               n_euro_20  * 20   +
               n_euro_50  * 50   +
               n_euro_100 * 100  +
               n_euro_200 * 200  +
               n_euro_500 * 500
    ;
    
    printf("\nThe total amount of money you have earned today is:   %.2f EU\n\n", cash_tot);
    
    return 0;
}
