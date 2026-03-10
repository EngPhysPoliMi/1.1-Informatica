
#include <stdio.h>
#include <math.h>

// Calcolo area triangolo qualsiasi
// S = sqrt(p*(p-AB)*(p-BC)*(p-AC))
// 1. Acquisisci lunghezza dei tre lati
// 2. Calcola il semiperimetro
// 3. Calcola S
// 4. Stampa S

// N.B.: I numeri devono essere coerenti secondo la disuguaglianza triangolare

int main(int argc, const char * argv[])
{
    float Lato_1,            // Lato 1
          Lato_2,            // Lato 2
          Lato_3,            // Lato 3
          Semi_perimetro,    // Semiperimetro
          Area_Triangolo;    // Area triangolo
    
    printf("Dammi la lunghezza del primo lato    -> ");
    scanf("%f",&Lato_1);
    
    printf("Dammi la lunghezza del secondo lato  -> ");
    scanf("%f",&Lato_2);
    
    printf("Dammi la lunghezza del terzo lato    -> ");
    scanf("%f",&Lato_3);
    
    if ((Lato_1 >= 0)&&
        (Lato_1 >= 0)&&
        (Lato_2 >= 0)
        )
    {
        // Verifica disuguaglianza triangolare
        
        if ((Lato_1 + Lato_2 > Lato_3)&&
            (Lato_1 + Lato_3 > Lato_2)&&
            (Lato_2 + Lato_3 > Lato_1)
            ) // è un triangolo?
        
        {  // Passo 2: Calcolo Semiperimetro
            
            Semi_perimetro = (Lato_1 + Lato_2 + Lato_3)/2;
            
           
            // Passo 3: Calcolo area triangolo
            
            Area_Triangolo = sqrt(
                                  Semi_perimetro*
                                  (Semi_perimetro-Lato_1)*
                                  (Semi_perimetro-Lato_2)*
                                  (Semi_perimetro-Lato_3)
                                   );
            
            // Passo 4: Stampare area triangolo
            
            printf("\nL'area del triangolo è %f\n\n", Area_Triangolo);
        }
        else
        {
            printf("\nI dati non permettono la costruzione di un triangolo.\n\n");
        }
   
    }
    else
    {
        printf("\nI numeri inseriti non sono validi.\n\n");
    }
    
    return 0;
}
