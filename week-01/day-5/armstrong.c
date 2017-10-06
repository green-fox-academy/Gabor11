#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
Write a simple program to check if a given number is an armstrong number.
The program should ask for a number. E.g. if we type 371, the program should print out: The 371 is an Armstrong number.
*/

main(){

    uint32_t number = 0;
    uint32_t num = 0;
    uint32_t counter = 1;   // I suppose at least one digit :)
    uint32_t powsum = 0;    // the sum of powers
    uint8_t digit = 0;

    printf("Please give me a number: ");
    scanf("%d", &number);

    num = number;

    //counting digits
    while (num/10 !=0) {
        num = num/10;
        counter++;
    }

    num = number;

    //generating sum of powers of digits
    for (int i = 0 ; i < counter ; i++) {
        digit = num % 10;
        powsum += pow(digit, counter);
        num = num / 10;

    }

    //checking whether the initial number equals 'powsum'
    if (powsum == number) {
        printf("The number %d is an Armstrong number.", number);
    } else {
        printf("The number %d is NOT an Armstrong number.", number);
    }

    return 0;
}
