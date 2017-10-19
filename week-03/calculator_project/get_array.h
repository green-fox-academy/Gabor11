#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void get_double_array(double* target_array, char* string, char* filter)
{
    double* val;
    val = double_tokenize(string, filter);
    for (int i = 0; i < double_arr_len(val); i++) {
        target_array[i] = val[i];
    }
}

void get_int_array(int* target_array, char* string, char* filter)
{
    int* val;
    val = int_tokenize(string, filter);
    for (int i = 0; i < int_arr_len(val); i++) {
        target_array[i] = val[i];
    }
}


void int_to_char_2d_array(int* operators, char oprtrs[][6])
{
    int j = 0;
    int k = 0;

    // filling up oprtrs
    for (int i = 0; i < int_arr_len(operators); i++) {
        while(operators[i] != 1) {
            oprtrs[j][k] = (int)operators[i];
            k++;
            i++;
        }
        oprtrs[j][k] = '\0';
        j++;
        k = 0;
    }
}
