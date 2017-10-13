#include <stdio.h>
#include <limits.h>
#include <string.h>

int main()
{
	int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};

    for (int i = 2; i < 8; i++ ){
        if (number_array[i-1] > number_array[i]){
            number_array[i] = number_array[i] + number_array[i - 1];
            number_array[i - 1] = number_array[i] - number_array[i - 1];
            number_array[i] = number_array[i] - number_array[i - 1];
        }
        if (number_array[i - 2] > number_array[i - 1]){
            number_array[i - 1] = number_array[i - 1] + number_array[i - 2];
            number_array[i - 2] = number_array[i - 1] - number_array[i - 2];
            number_array[i - 1] = number_array[i - 1] - number_array[i - 2];
        }
    }

    printf("The two biggest number are: %d and %d.", number_array[6], number_array[7]);


	//TODO:
	// Write a C program to find the two largest element in an array using only 1 for loop
	// From <limits.h> use INT_MIN: this is the least integer

	return 0;
}
