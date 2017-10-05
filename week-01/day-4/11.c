#include <stdio.h>

/*
Write a program that prints the numbers from 1 to 100.
But for multiples of three print "Fizz" instead of the number
and for the multiples of five print "Buzz".
For numbers which are multiples of both three and five print "FizzBuzz".
But this time, use switch
*/

int main() {

    for(int x = 0; x <101; x++)
    {

    switch (x%15)
            {
            case 0:
                printf("FizzBuzz\n");
                break;
            case 5:
            case 10:
                printf("Buzz\n");
                break;
            case 3:
            case 6:
            case 9:
            case 12:
                printf("Fizz\n");
                break;
            default :
                printf("%d\n",x);
            }

    printf("%d\n", x);

    }

    return 0;
}
