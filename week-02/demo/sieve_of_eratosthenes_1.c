#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define true 1
#define false 0

int main()
{
    int8_t primes[10000000];

    //int8_t primes[1000000];

    // setting all elements to 'true'
    for(int32_t i = 0; i < 10000000; i++){
        primes[i] = true;
    }

    // setting non-prime elements to 'false' (this algorithm implements the "sieve of Eratosthenes")
    int i = 2;
    while(i < 3163){
        if (primes[i] == true){
            int32_t j = i * i;
            while(j < 10000000){
                primes[j] = false;
                j += i;
            }
        }
        i++;
    }

    //writing data to the screen
    for (int32_t i = 2; i < 10000000; i++){
        if (primes[i] == true){
            printf("%d\n",i);
        }
    }

    return 0;
}

