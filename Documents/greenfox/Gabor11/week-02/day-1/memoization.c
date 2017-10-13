#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

// create a function which returns a Fibonacci number like in the example code
// this time do it with memoization
// again the parameters value should be stored in a .h file

int fibonacci(int number);
int stored[100] = {false};

int lookup[100];

int main()
{
    lookup[0] = 1;
    lookup[1] = 1;
    stored[0] = true;
    stored[1] = true;
    printf("%d", fibonacci(12));
    return 0;
}

int fibonacci(int number)
{

    if (stored[number]){
        return lookup[number];
    } else {
        lookup[number] = fibonacci(number - 1) + fibonacci(number - 2);
        printf("%d\n", lookup[number]);
        stored[number] = true;
        return lookup[number];
    }
}



