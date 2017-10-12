#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 32;
    int y = 20;
    int temp;

    printf("The greatest common divisors of %d and %d:\n", x, y);

    if (y>x) // if y is bigger --> swap values
    {
        y=x+y;
        x=y-x;
        y=y-x;
    }

    do // the algorithm of Euclid
    {
    temp = y;
    y = x%y;
    x = temp;
    }while(y!=0);

    printf("%d", temp);

    return 0;
}
