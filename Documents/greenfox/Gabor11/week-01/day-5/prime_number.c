#include <stdio.h>

/*
Create a program which prints out oll the prime numbers
aslo add a feature where you can tell the from - to limits
for example :
from = 11;
to = 34;
output :
13, 17, 19, 23, 29, 31 , this is 6 prime numbers
*/

void main()
{
    int from = 1;
    int to = 1000;
    int i = from;
    int j = 2;
    int count =0;

    // start trials of numbers from 'i' = 'from' to 'to'
    while (i < to){

        //each 'i' must be tested by modulo operator from 2 (stored initially in 'j') to 'i'
        //whenever the result 0 it shows that it is not a prime
        while(j < i){
            if(i%j == 0) {
                break;
            }
                j++;
        }
        //from the value of 'j' we can tell whether the number (stored in 'i') is a prime or not
        if(j == i) {
            printf("%d\n", i);
            count++;
        }
        i++;
        //'j' must be set 2 again
        j = 2;
    }

    //final message
    printf("These are %d prime numbers.", count);


    return 0;




}
