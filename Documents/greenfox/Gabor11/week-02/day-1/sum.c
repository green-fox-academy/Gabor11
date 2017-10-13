#include <stdio.h>
#include <stdlib.h>
#include "sum.h"

// Write a function called `sum` that sum all the numbers
// until the given parameter which you store in a .h file

int sum();

int main()
{
    printf("The sum: %d\n", sum(treshold));

    return 0;
}

int sum (int treshold_value){
    int sum_ = 0;
    for (int i = 0 ; i < treshold_value ; i++){
        sum_ += i;
    }
    return sum_;
}
