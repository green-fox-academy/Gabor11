#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int int_pnt_len(int* array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}
