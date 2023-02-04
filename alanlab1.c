#include <stdio.h>
#include <math.h>
int main(void){
    int a;
    printf("input number 'A' up to 99999: ");
    scanf("%6d", &a);
    int b;
    printf("input number 'B' up to 99999: ");
    scanf("%6d", &b);

    printf("A + B = %d\n", a + b);
    printf("A - B = %d\n", a - b);
    printf("A * B = %d\n", a * b);
    printf("A / B = %d\n", a / b);
    printf("A % B = %d\n", a % b);
    printf("A ^ B = %d\n", (int)pow(a, b));
    return 0;
}