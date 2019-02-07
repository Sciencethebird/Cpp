#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int num, gs=101;
    srand(time(NULL));
    num=(rand()%100)+1;
    printf("I have a number between 1 and 100.\n");
    printf("Can you guess my number?\n");
    printf("Please type your first guess.\n");


    while(gs != num)
    {
        scanf("%d", &gs);
        if(gs == num)
        {
            printf("Excellent! You guessed the number!\n");
            break;
        }

        if(gs>num)
        {
            printf("Too high. Try again.\n");
            continue;
        }

        if(gs<num)
        {
            printf("Too low. Try again.\n");
            continue;
        }

    }
    return 0;
}
