//
//  main.c
//  Pile_or_stacks_1
//
//  Created by Cendron Pietro on 12/12/20.
//
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
