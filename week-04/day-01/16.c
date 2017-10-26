#include <stdio.h>

int assort_odd_elements(int *array, int size);
void delete_from_array(int *array, int i, int size);

int main(void)
{
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66, NULL};


    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements

    printf("elements: %d\n", assort_odd_elements(num_array, int_arr_len(num_array)));

    for (int i = 0; i < int_arr_len(num_array); i++) {
        printf("%d\n", num_array[i]);
    }

    return 0;
}

int assort_odd_elements(int *array, int size)
{
    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 1) {
            delete_from_array(array, i, int_arr_len(array));
            i--;
        }
    }
    return int_arr_len(array);

}

void delete_from_array(int *array, int i, int actual_size)
{
    for (int j = i + 1; j < actual_size; j++) {
        array[j - 1] = array[j];
    }
    array[actual_size - 1] = NULL;
}

int int_arr_len(int *array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}
