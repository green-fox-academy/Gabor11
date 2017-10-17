#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

void binary_adder(char* a, char* b);

int main()
{

    char a[20];
    char b[20];

    printf("Give me a binary number: ");
    scanf("%s", &a);
    printf("Give me another binary number: ");
    scanf("%s", &b);

    binary_adder(a, b);

    return(0);
}

void binary_adder(char* a, char* b)
{
    long res_a = 0;
    long res_b = 0;
    char *ptr;
    char buffer[30] = {0};

    res_a = strtol(a, &ptr, 2);
    res_b = strtol(b, &ptr, 2);

    itoa(res_a + res_b, buffer, 2);

    printf("%s (2)\n", buffer);
    printf("%d (10)\n", res_a + res_b);
}
