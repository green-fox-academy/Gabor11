#include <stdio.h>
#include <stdlib.h>

/*
swap the values of the to number
print out first the original values then print out the swaped values
*/

int main()
{
    int x = 32;
    int y = 20;
    int swap;

    printf("x:%d\ny:%d\n\n", x,y);

    swap = x;
    x = y;
    y = swap;

    printf("x:%d\ny:%d\n\n", x,y);
}
