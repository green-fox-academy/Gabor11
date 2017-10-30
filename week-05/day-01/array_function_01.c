#include <stdio.h>
#include <stdint.h>


/*
 * Create a function that takes an array as argument and it's length. Determine the right data types to do this.
 * This function should order the arguments in ascending order and return this in a new sorted array.
 *
 * Create a second function that takes 3 arguments. An array, it's length and a number it is searching for.
 * The function should return the index of the number when found or -1 if it's not part of the array.
 * IMPORTANT: this function expects a sorted array and uses the strategy we used when we play guess the number.
 *
 *
 * In the main function create an unsorted array filled with random numbers, Make it 50 long.
 * Try 2 scenarios:
 *    * In the first: You pick a random element in the unosrted array and check at which index it is after the array is sorted.
 *    * In the second: You pick a number You are sure is not in the array. Check whether the search function returns the right number.
 * Print out what You need to check these.
 */
int searcher(int *array, int8_t length, int to_look);

int main()
{
    int arr[] = {12, 11, 9, 23, 10, 8, 4, 50, 43, 32};
    int to_look = 8;
    int result = 0;

    sorter(arr, 10);

    result = searcher(arr, 10, to_look);

    if(result >= 0)
        printf("The number %d is at the position %d", arr[result], result);
    else
        printf("The number is unfortunately not found.");


    return 0;
}

void sorter(int *array, int8_t length)
{
    int aux = 0;
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (array[i] > array[j]) {
                aux = array[i];
                array[i] = array[j];
                array[j] = aux;
            }
        }
    }
}

int searcher(int *array, int8_t length, int to_look)
{
    int aux = 0;
    int min = 0;
    int max = length - 1;

    while (to_look >= array[min] && to_look <= array[max]) {
        aux = (max + min) / 2;
        if (array[aux] == to_look) {
            return aux;
        } else if (array[aux] > to_look) {
            max = aux;
        } else {
            min = aux;
        }
    }

    return -1;
}

