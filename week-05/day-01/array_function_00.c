#include <stdio.h>
#include <stdint.h>

/*
 * Create a function that takes an array of integers as an argument (a pointer) and it's length as an unsigned integer.
 * The function should sort the elements of the array in ascending order.
 *
 * Print it out before and after to be able to check whether it works as supposed.
 */

void sorter(int *array, int8_t length);

int main()
{
    int arr[] = {12, 11, 9, 23, 10, 8, 4, 50, 43, 32};

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    sorter(arr, 10);

    printf("\n\n");

    for (int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

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
