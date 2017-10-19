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

    int operators[256] = {'\0'};        // receiving output of tokenize
    char oprtrs[256][6] = {'\0'};

void int_to_char_2d_array(int* operators, char oprtrs[][6])
{
    int j = 0;
    int k = 0;

    // filling up oprtrs
    for (int i = 0; i < int_pnt_len(operators); i++) {
        // char buffer[6] = {'\0'};
        while(operators[i] != 1) {
           // buffer[k] = operators[i];
            oprtrs[j][k] = operators[i];
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
