#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int double_arr_len(double* array)
{
    int i = 0;
    while ((int)array[i] != NULL) {
        i++;
    }
    return i;
}

int char2d_pnt_len(char array[][6])
{
    int i = 0;
    while (array[i][0] != NULL) {
        i++;
    }
    return i;
}
