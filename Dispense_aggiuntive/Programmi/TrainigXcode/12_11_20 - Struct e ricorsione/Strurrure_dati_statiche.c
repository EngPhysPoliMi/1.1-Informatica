#include <stdio.h>
#define MAX 30
typedef enum {
    portiere,
    difensore,
    centrocampista,
    attaccante
} roleType;
typedef struct
{
    int number;
    int scoregol;//i gol fatti dal portiere sono i gol subiti dalla squadra
    roleType role;
    char name[10];
}player;

int InsertPlayer (player g[], int i);//i lunghezza attuale, return nuova lunghezza

void contagol (player g[], int i, int *goldone, int *golsubiti, int *golatt, int *golcent, int *goldif);

player bestplayer(player g[], int i);

void stamp(player g[],int i);

int main()
{
    player giocatori[MAX];

    int numGiocatori=0;
    int totalegolsubiti=0;
    int totalegolfatti=0;
    int golAtt=0;
    int golDif=0;
    int golCent=0;

    player bplayer;
    int r;

    do
    {
        printf("\nMENU\n1)Inserisci giocatori\n2)calcola goal\n3)Trova migliore giocatore\n4)stampa giocatori\n5)ESCI\n\n");
        scanf("%d",&r);
        switch(r)
        {
            case 1:
                numGiocatori=InsertPlayer(giocatori,numGiocatori);
                break;
            case 2:
                contagol(giocatori,numGiocatori,&totalegolfatti,&totalegolsubiti,&golAtt,&golCent,&golDif);
                printf("goal fatti: %d\ngoal subiti: %d\ngoal attcanti: %d\n goal centrocampisti: %d\n goal difensori: %d",totalegolfatti,totalegolsubiti,golAtt,golCent,golDif);
                break;
            case 3:
                bplayer=bestplayer(giocatori, numGiocatori);
                printf("il giocatore migliore e': %s che ha numero %d, ha segnato %d goal.",bplayer.name,bplayer.number,bplayer.scoregol);
                printf("Ha il ruolo di");
                switch (bplayer.role)
                {
                    case portiere:
                        printf("Portiere\n");
                        break;
                    case difensore:
                        printf("Difensore\n");
                        break;
                    case centrocampista:
                        printf("Centrocampista\n");
                        break;
                    case attaccante:
                        printf("Attacante\n");
                        break;
            
        }
                break;
            case 4:
                stamp(giocatori, numGiocatori);
                break;
            case 5:
                printf("arrivederci");
                break;
            default:
                printf("opzione non supportata");
                break;
        }

    }while(r!=5);

    return 0;
}

int InsertPlayer (player g[], int i)
{

    printf("inserisci numero: ");
    scanf("%d", &g[i].number);

    printf("inserisci goal fatti: ");
    scanf("%d", &g[i].scoregol);

    printf("Inserisci il ruolo del giocatore:(portiere, %d difensore %d centrocampista %d attaccante %d): ", portiere, difensore, centrocampista,attaccante);
    scanf("%d", &g[i].role);

    printf ("Inserisci il nome: ");
    scanf("%s",&g[i].name);
    
    return i+1;
}

void contagol (player g[], int i, int *goldone, int *golsubiti, int *golatt, int *golcent, int *goldif)
{
    int k;
    *goldone=0;
    *golsubiti=0; 
    *golatt=0;
    *golcent=0;
    *goldif=0;

    for (k=0;k<i;k++)
    {
        switch(g[k].role)
        {
            case portiere:
                *golsubiti=*golsubiti+g[k].scoregol;
                break;
            case difensore:
                *goldif=*goldif+g[k].scoregol;
                break;
            case centrocampista:
                *golcent=*golcent+g[k].scoregol;
                break;
            case attaccante:
                *golatt=*golatt+g[k].scoregol;
                break;
        }
        
    }
    *goldone=*golatt+*golcent+*goldif;

}

player bestplayer(player g[], int i)
{
    player best;
    best.scoregol=0;
    best.number=0;
    best.role=-1;
    int k;
    for(k=0;k<i;k++)
    {
        if ((g[k].role!=0)&&(g[k].scoregol>best.scoregol))
            best=g[k];
            
    }
    return best;
}

void stamp(player g[],int i)
{
    for (int j=0;j<i;j++)
    {
        
        switch (g[j].role)
        {
            case portiere:
                printf("Il giocatore %s ha numero %d ha subito %d goal", g[j].name, g[j].number,g[j].scoregol);
                printf(" e si trova nel ruolo di ");
                printf("Portiere\n");
                break;
            case difensore:
                printf("Il giocatore %s ha numero %d ha segnato %d goal", g[j].name, g[j].number,g[j].scoregol);
                printf(" e si trova nel ruolo di ");
                printf("Difensore\n");
                break;
            case centrocampista:
                printf("Il giocatore %s ha numero %d ha segnato %d goal", g[j].name, g[j].number,g[j].scoregol);
                printf(" e si trova nel ruolo di ");
                printf("Centrocampista\n");
                break;
            case attaccante:
                printf("Il giocatore %s ha numero %d ha segnato %d goal", g[j].name, g[j].number,g[j].scoregol);
                printf(" e si trova nel ruolo di ");
                printf("Attacante\n");
                break;
            
        }
    }
}