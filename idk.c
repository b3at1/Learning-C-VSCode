#include <stdio.h>

int adr(int num, int orig){
    if(num % (orig - 1) == 0){
        return num;
    }
        
    return adr(++num, --orig);
}

int main(void){
    printf("In --> Out\n");
    for(int i = 3; i <= 20; i++){
        printf("%d --> %d\n", i, adr(i, i));
    }
    printf("In --> Out2\n");
    for(int i = 3; i <= 20; i++){
        printf("%d --> %d\n", i, 2*(i - 1));
    }
}