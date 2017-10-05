#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
	// Write a program that prints the numbers from 1 to 100.
	// But for multiples of three print "Fizz" instead of the number
	// and for the multiples of five print "Buzz".
	// For numbers which are multiples of both three and five print "FizzBuzz".

	uint8_t a = 100;
    uint8_t x = 1;

    while (x <= a)
    {
        if ((x%3 == 0) && (x%5 == 0)) {printf("FizzBuzz\n");}
        else if (x%5 == 0) {printf("Buzz\n");}
        else if (x%3 == 0) {printf("Fizz\n");}
        else {printf("%d%\n", x);}
 /*       switch (false)
            {
            case x%3 :
                printf("Fizz");
            case x%4 :
                printf("\n");
            case x%5 :
                printf("Buzz\n");
                break;
            default :
                printf("%d\n",x);
            }
        printf("%d\n", x);
*/
        x += 1;

    }

    printf("\n\n");
    x = 0;

    do
    {
        if ((x%3 == 0) && (x%5 == 0)) {printf("FizzBuzz\n");}
        else if (x%5 == 0) {printf("Buzz\n");}
        else if (x%3 == 0) {printf("Fizz\n");}
        else {printf("%d%\n", x);}
        x += 1;
    }while(x <= a);

    printf("\n\n");

    for(uint8_t i = 1; i <= a ; i++)
    {
        if ((i%3 == 0) && (i%5 == 0)) {printf("FizzBuzz\n");}
        else if (i%5 == 0) {printf("Buzz\n");}
        else if (i%3 == 0) {printf("Fizz\n");}
        else {printf("%d%\n", i);}
    }

	return 0;
}
