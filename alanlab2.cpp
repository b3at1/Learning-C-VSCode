#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>

struct datham{
    int hams;
    std::string name;
}datham;

int main(){
/*
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
*/

    printf("input your number of hams: ");
    struct datham guy;
    std::cin >> guy.hams;
    printf("input your datham name: ");
    std::cin >> guy.name;
    
    std::cout << "datham name: " << guy.name << "\ndatham hams: " << guy.hams << std::endl;
    return 0;
}