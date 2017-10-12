#include <stdio.h>
#include <stdlib.h>
#include "factorio.h"
#include <stdint.h>

// create a function called `factorio`
// that returns it's input's factorial with and without recursion
// again the parameters value should be stored in a .h file
//

uint64_t factorio (uint64_t input);
uint64_t factorio_for (uint64_t input);

int main()
{
    printf("%d\n",factorio(NUM));
    printf("%d\n",factorio(NUM2));
    printf("%d\n",factorio(NUM3));

    printf("\n\n");

    printf("%d\n",factorio_for(NUM));
    printf("%d\n",factorio_for(NUM2));
    printf("%d\n",factorio_for(NUM3));

    return 0;
}

uint64_t factorio (uint64_t input){
    if (input == 1){
        return 1;
    } else {
        return factorio(input - 1) * input;}

}

uint64_t factorio_for(uint64_t input){
    uint64_t product = 1;
    for(uint64_t i = 1 ; i <= input ; i++){
        product *= i;
    }
    return product;
}
