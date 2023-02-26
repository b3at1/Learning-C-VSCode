#include <stdio.h>

int main(void)
{
    int x = 5;
    int *y = &x;
    printf("hello world!\n");
    printf("Value of y points to x: %d\n", *y);
    return 0;
}