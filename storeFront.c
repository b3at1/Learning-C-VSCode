#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>
#define MAPSIZE 10
/*
    BallMart is a store that sells balls
    You can see what balls are in stock, 
    make purchases, 
    view your receipt
*/  

//map struct to make balls with name (key) and price (value) as well as a quantity
struct map{
    char* key;
    int value;
    int quant;
};
struct map storeFront[MAPSIZE];
struct map beginStore[MAPSIZE];
//populates the storeFront with random prices and quantities
void initmap(void){ 
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
        beginStore[i].value = rand() % (max_price - min_price) + min_price + 1; //set random ball price
        storeFront[i].quant = rand() % (max_quant - min_quant) + min_quant + 1; //set random ball quant
        storeFront[i].key = balls[i];
        beginStore[i].key = balls[i];
    }
    
}

//displays idx, name, and price
void prntStore(){ 
    int idx;
    for(idx = 0; idx < MAPSIZE; idx++){
        //this seems like an awful way to concat stuff but I guess it works
        char *c = "c";
        char quant[50] = "";
        sprintf(quant, "%d", storeFront[idx].value);
        strncat(quant, c, 49 - strlen(quant)); //we have 49-len(quant) space left because of \0
        printf("%-5d %-14s %-6s %3d\n", idx, storeFront[idx].key, quant, storeFront[idx].quant);
    }
}

void prntReceipt(){ 
    int idx;
    for(idx = 0; idx < MAPSIZE; idx++){
        //this seems like an awful way to concat stuff but I guess it works
        if(beginStore[idx].quant != 0){ //only print stuff that got purchased
            char *c = "c";
            char quant[50] = "";
            sprintf(quant, "%d", beginStore[idx].value);
            strncat(quant, c, 49 - strlen(quant)); //we have 49-len(quant) space left because of \0
            printf("%-5d %-14s %-6s %3d\n", idx, beginStore[idx].key, quant, beginStore[idx].quant);        
        }

    }
}

//attempts to purchase item ID in respective quant, returns 0 if failed to purchase
int makePurchase(int *wallet, int id, int quant){
    int ret = 1;
    int newQuant = storeFront[id].quant - quant;
    int newBal = *wallet - (quant * storeFront[id].value);
    int maxAfford = *wallet / storeFront[id].value;
    printf("_______________________________________\n");

    if(id < 0 || id > 9){
        printf("ID not recognized, please try again!\n");
        ret = 0;
    }
    else if(quant < 1){
        printf("You can't buy that many, silly!\n");
        ret = 0;
    }
    else if(newQuant < 0){
        printf("We don't have that many in stock :c\n");
        printf("There are currently %d of that item.\n", storeFront[id].quant);
        ret = 0;
    }
    else if(newBal < 0){
        printf("You can't afford that!\n");
        printf("You can afford at most %d of that item.\n", maxAfford);
        ret = 0;
    }
    else{
        *wallet = newBal;
        storeFront[id].quant = newQuant;
        beginStore[id].quant += quant;
    }
    
    return ret;
}

void receipt(int beginWallet, int wallet){
        printf("_______________RECEIPT_________________\n");
        printf("ID:   Name:%16s%13s\n", "Price:", "Quantity: ");
        prntReceipt();
        printf("_______________________________________\n");
        printf("Your total is: %dc\n", beginWallet - wallet);
        printf("Thank you for shopping at BallMart, please come again!\n");
     //reuse map
}

//main purchase functionality
void purchaseLogic(){
    srand(time(NULL) ^ getpid()); //seed random no idea what getpid() does but it seems to make the random better
    int wallet = rand() % (15000 - 1000) + 1000 + 1;
    int beginWallet = wallet;
    int *wall = &wallet; //we need a pointer so it can be modified in methods
    char decide;
    int c;
    //first round of purchase
    printf("You have %dc in your wallet!\n", wallet);
    do{
        fflush(stdin); 
        printf("Do you wanna buy balls? (y/n): ");
        scanf("%1c", &decide);
                while ((c = getchar()) != '\n' && c != EOF) {
        }
        decide = tolower(decide);

    }
    while(decide != 'y' && decide != 'n');

    //subsequent purchases
    if(decide == 'y'){
        while(decide == 'y'){
            printf("ID:   Name:%16s%13s\n", "Price:", "Quantity: ");
            prntStore();
            printf("_______________________________________\n");
            printf("Type in the ID of an item to purchase: ");
            int item_id = -1; //this way if input doesn't work out, will stay < 0
            fflush(stdin); //flushes stdin
            scanf("%1d", &item_id); //changed back to %1d to fix seg fault

            //printf("\n%d\n", item_id); //DEBUG SHIZZZ, FIGURE THIS OUT
            /* ok so the solution I have for now is just limiting to %1d, replace id with -1 on each new run*/

            fflush(stdin); //flushes stdin

            printf("Type in the quantity to purchase: ");
            int item_quant;            
            scanf("%1d", &item_quant);
            int made = makePurchase(wall, item_id, item_quant); //make sure to pass in wall (the address), passing in wall* will derefence, meaning it passes in wallet
            if(made == 1)
                printf("Thank you for your purchase <3\n", wallet);
            printf("You have %d left in your wallet.\n", wallet);
            fflush(stdin); //flushes stdin

            printf("Make another purchase? (y/n): ");
            scanf("%1c", &decide);
            printf("\n"); //flush stdout
            fflush(stdin); 
            decide = tolower(decide);
            if(decide == 'n')
                receipt(beginWallet, wallet);
            }
        }

    else if(decide == 'n'){
        printf("\nbruh... you're making me cry :'(\n");
    }
    else
        printf("what did you do.... this shouldn't be reachable...\n");
}


int main(void){
    initmap();
    printf("Welcome to BallMart!\nWe sell balls. You should buy them <3\n");
    purchaseLogic();
    return 0;
}