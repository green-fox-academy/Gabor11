#include <stdio.h>
int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];

    my_array[0] = 200;

    for (int i = 0; i < 50; i++){
        while(my_array[i] % 85 != 0){
            my_array[i]--;
        }
        my_array[i+1] = my_array[i] - 1;
    }
    for (int i = 0; i < 50; i++){
        printf(" %d", my_array[i]);
    }




    return 0;
}
