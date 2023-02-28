#include <stdio.h>
#include <math.h>
#include <time.h>
#define R "ROCK"
#define P "PAPER"
#define S "SCISSORS"

void gameLogic(char *pm, char *bm){
    printf("You guessed: %s\nBot guessed: %s\n", pm, bm);
    if((strcmp(pm, R) == 0 && strcmp(bm, S) == 0) ||
        (strcmp(pm, S) == 0 && strcmp(bm, P) == 0) ||
        (strcmp(pm, P) == 0 && strcmp(bm, R) == 0))
        printf("You won!\n");
    else if(!strcmp(pm, bm)) //means it is 0, so theyre equal
        printf("You tied.\n");
    else
        printf("You lost.\n");
    return;
}
int main(void){
    srand(time(NULL) ^ getpid()); //seed random
    printf("lets play rock paper scissors.\n");
    char *pm = malloc(10); //player move
    while(1){
        printf("Enter %s (R) %s (P) %s (S): ", R, P, S);
        scanf(" %1s", pm); //scan single char to convert
        getchar(); // consume newline character
        if((strcmp(pm, "R") && strcmp(pm, "P") && strcmp(pm, "S")))
            continue; //retry until input valid
        if(strcmp(pm, "R"))
            strcpy(pm, R);
        else if(strcmp(pm, "P"))
            strcpy(pm, P);
        else
            strcpy(pm, S);
        char choices[3][10] = {R, P, S};
        char *bm = &choices[rand() % 3]; //bot move takes from arr idx 0-2
        gameLogic(pm, bm);
        break;
    }

    return 0;
}