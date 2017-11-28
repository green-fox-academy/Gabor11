#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define true 1
#define false 0

int main()
{
    // allocating some memory for 'primes' otherwise it would not run (till 10 million) :)
    int8_t *primes = malloc (sizeof(int8_t) * 100000000);

    // preparing a file to write the prime numbers into
    FILE * fp;
    fp = fopen ("prime_numbers.csv","w");

    // setting all elements to 'true'
    for(int32_t i = 0; i < 100000000; i++){
        primes[i] = true;
    }

    // setting non-prime elements to 'false' (this algorithm implements the "sieve of Eratosthenes")
    for (int i = 2; i < 10000; i++){
        if (primes[i] == true){
            int32_t j = i * i;
            while(j < 100000000){
                primes[j] = false;
                j += i;
            }
        }
    }

    //writing data into our file
    for (int32_t i = 2; i < 100000000; i++){
        if (primes[i] == true){
            fprintf (fp, "%d\n",i);
        }
    }

    fclose (fp);

    return 0;
}
