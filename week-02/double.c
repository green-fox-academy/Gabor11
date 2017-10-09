#include <stdio.h>
#include <stdlib.h>
#include "double.h"

// create a function called `doubling` that doubles it's input parameter
// again the parameters value should be stored in a .h file

int doubling();

int main()
{
    printf("Result of doubling: %d\n", doubling(INPUT));
    return 0;
}

int doubling(int input){
    return 2 * input;

}
