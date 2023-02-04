#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAPSIZE 10
/*
    The Ball Store is a store that sells balls
    You can see what balls are in stock, 
    make purchases, 
    view your receipt
*/  
//map struct to make balls with name (key) and price (value)
struct map{
    char* key;
    int value;
    int quant;
};

struct map storeFront[MAPSIZE];
void initmap(void){ //creates a map with random prices
    srand(time(0));
    int i;
    /*
        for(i = 0; i < MAPSIZE; i++){       //expierenmenting with concatination
        storeFront[i].value = i;
        char buffer[50];
        sprintf(buffer, "%d", i);
        storeFront[i].key = malloc(strlen("a") + strlen(buffer) + 1);
        strcpy(storeFront[i].key, "a");
        strcat(storeFront[i].key, buffer);
    }
    */
    char* balls[] = { "Blue Ball", "Pee Ball", "Hairy Ball", "Pink Ball", "Bouncy Ball", "Nice Ball", "Ancient Ball", "Steamed Ball", "Ball Ball", "Sticky Ball"};

    for(i = 0; i < MAPSIZE; i++){
        int max_price = 5000;
        int min_price = 100;
        int min_quant = 0;
        int max_quant = 5;
        storeFront[i].value = rand() % (max_price - min_price) + min_price + 1; //set random ball price
        storeFront[i].quant = rand() % (max_quant - min_quant) + min_quant + 1; //set random ball quant
        storeFront[i].key = balls[i];
    }
    
    
}

void prntMap(void){ //displays idx, name, and price
    int idx;
    for(idx = 0; idx < MAPSIZE; idx++){
        char *c = "c";
        char quant[50] = "";
        sprintf(quant, "%d", storeFront[idx].value);
        strncat(quant, c, 49 - strlen(quant));       
        printf("%-5d %-14s %-6s %3d\n", idx, storeFront[idx].key, quant, storeFront[idx].quant);
    }
}


int main(void){
    initmap();
    srand(time(0)); //seed random
    int wallet = rand() % (30000 - 1000) + 1000 + 1;

    printf("Welcome to the Ball Store!\nWe sell balls. You should buy them <3\n\n");
    printf("You have %dc in your wallet!\n", wallet);

    
    char decide;
    do{
        printf("Do you wanna buy balls? (y/n): ");
        scanf("%1c", &decide);
        printf("\n"); //flush stdout
        decide = tolower(decide);

    }
    while(decide != 'y' && decide != 'n');


    if(decide == 'y'){
        printf("ID:   Name:%16s%13s\n", "Price:", "Quantity: ");
        prntMap();  
    }
    else if(decide == 'n'){
        printf("bruh... you're making me cry :'(\n");
    }
    else
        printf("what did you do.... this shouldn't be reachable...\n");

    
    return 0;
}