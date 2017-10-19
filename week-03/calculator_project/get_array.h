#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void get_array(double* target_array, char* string, char* filter)
{
    double* val;
    val = tokenize(string, filter);
    for (int i = 0; i < double_arr_len(val); i++) {
        target_array[i] = val[i];
    }
}


void double_to_char_2d_array(double* operators, char oprtrs[][6])
{
    int j = 0;
    int k = 0;

    // filling up oprtrs
    for (int i = 0; i < double_arr_len(operators); i++) {
        // char buffer[6] = {'\0'};
        while(operators[i] != 1) {
           // buffer[k] = operators[i];
            oprtrs[j][k] = (int)operators[i];
            k++;
            i++;
        }
        oprtrs[j][k] = '\0';
        // buffer[k] = '\0';
        // filling up 'oprtrs' with an operator from the buffer :)
        /* for (int l = 0; l < 6; l++) {
            oprtrs[j][l] = buffer[l];
        } */
        j++;
        k = 0;
    }
}
