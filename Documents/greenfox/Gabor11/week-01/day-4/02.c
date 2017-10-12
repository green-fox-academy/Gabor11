#include <stdio.h>
#include <stdlib.h>

/*
write a program to check whether a given number is positive or negative
*/

int main()
{
    int a = 212;

    while (a < 0)
    {
        printf("This number is negative.");
        break;
    }
    while (a == 0)
    {
        printf("This number is zero.");
        break;
    }
    while (a > 0)
    {
        printf("This number is positive.");
        break;
    }

    return 0;
}
