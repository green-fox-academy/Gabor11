#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// functions to tokenize the given input

double* double_tokenize(char* string, char s[12])
{
    // making a new char array to keep the initial string unchanged
    char* tempstr = calloc(strlen(string) + 1, sizeof(char));
    strcpy(tempstr, string);
    char* token;
    static double values[30] = {'\0'};
    int i = 0;

    // starting to process the string
    token = strtok(tempstr, s);

    while(token != NULL) {
        // dealing with operators
        if (!is_num(token)) {
            for (int j = 0; j < strlen(token); j++) {
                values[i] = token[j];
                i++;
            }
            values[i] = 1;
            i++;
            token = strtok(NULL, s);
        } else { // dealing with numbers
        //printf( "%s\n", token);
        values[i] = atof(token);
        token = strtok(NULL, s);
        i++;
        }
    }
    values[i] = '\0';
    return values;
}

int* int_tokenize(char* string, char s[12])
{
    // making a new char array to keep the initial string unchanged
    char* tempstr = calloc(strlen(string) + 1, sizeof(char));
    strcpy(tempstr, string);
    char* token;
    static int values[30] = {'\0'};
    int i = 0;

    // starting to process the string
    token = strtok(tempstr, s);

    while(token != NULL) {
        // dealing with operators
        if (atoi(token) == NULL) {
            for (int j = 0; j < strlen(token); j++) {
                values[i] = token[j];
                i++;
            }
            values[i] = 1;
            i++;
            token = strtok(NULL, s);
        } else { // dealing with numbers
        //printf( "%s\n", token);
        values[i] = atoi(token);
        token = strtok(NULL, s);
        i++;
        }
    }
    values[i] = '\0';
    return values;
}

// functions to collect tokenized data into arrays
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

// serves to store input operators in a two dimensional array  --> better handling
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

// functions dealing with the length of different arrays

int double_arr_len(double* array)
{
    int i = 0;
    while ((int)array[i] != NULL) {
        i++;
    }
    return i;
}

int int_arr_len(int* array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}

int char2d_arr_len(char array[][6])
{
    int i = 0;
    while (array[i][0] != NULL) {
        i++;
    }
    return i;
}

// 'remove_spaces' accepts a char[] argument and returns a char[] without the spaces :)
char* remove_spaces(char* input)
{
    int i, j;
    i = j = 0;
    char *output = input;
    for (i, j ; i < strlen(input) ; i++, j++)
    {
        if (input[i]!=' ')
            output[j]=input[i];
        else
            j--;
    }
    output[j] = '\0';
    return output;
}

// gives back '1' if the input can be a number and '0' if it cannot
int is_num(char* str)
{
    int ret = 0;
    int count = 0;
    int dot = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (47 < str[i] && str[i] < 58)
            count++;
         else if (str[i] == 46)
            dot++;
    }

    if (count == strlen(str))
        return 1;
    else if (count == strlen(str) - 1 && dot == 1)
        return 1;
    else
        return 0;
}



// this function deals with emptying the variables which are used
void clear_database(char string [], int operators[], char oprtrs[][6], double numbers[], double result, char string_out[], char error_out[])
{
    char empty[6] = {'\0'};
    int size = sizeof(string[0]);
    int len = strlen(string);

    memset(string, '\0', sizeof(string[0])*strlen(string));
    /*
    for (int i = 0; i < strlen(string); i++) {
        string[i] = '\0';
    }
    */
    len = int_arr_len(operators);

    for (int i = 0; i < len; i++) {
        operators[i] = 0;
    }


    // memset(operators, 0, sizeof(operators[0])*len);

    len = char2d_arr_len(oprtrs);

    for (int i = 0; i < len; i++) {
        strcpy (oprtrs[i],empty);
       /*     for ( int j = 0; j < 6; j++) {

            } */
    }

    len = double_arr_len(numbers);

    for (int i = 0; i < len; i++) {
        numbers[i] = 0;
    }

    len = strlen(string_out);

    for (int i = 0; i < len; i++) {
        string_out[i] = '\0';
    }

    len = strlen(error_out);

    for (int i = 0; i < len; i++) {
        error_out[i] = '\0';
    }

    result = 0;

}

