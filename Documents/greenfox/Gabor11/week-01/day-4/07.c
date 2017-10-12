#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = 12;
    bool odd = num % 2;

    switch (odd)
        {
        case true  :
            printf("The number %d is odd.", num);
            break;
        case false :
            printf("The number %d is even.", num);
            break;
        default :
            printf("Is that a number?");
        }

    return 0;
}
