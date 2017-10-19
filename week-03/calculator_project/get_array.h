#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void get_array(int* target_array, char* string, char* filter)
{
    int* val;
    val = tokenize(string, filter);
    for (int i = 0; i < int_pnt_len(val); i++) {
        target_array[i] = val[i];
    }
}
