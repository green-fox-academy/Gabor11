#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "interface.h"
#include "data_handling.h"
#include "do_math.h"

void start_message(); // outsourced
double* tokenize(char* string, char s[12]); // outsourced
char* remove_spaces(char* input);
int double_arr_len(double* array);
void set_cursor_pos(int x, int y);
void get_double_array(double* target_array, char* string, char* filter);
void get_int_array(int* target_array, char* string, char* filter);
void int_to_char_2d_array(int* operators, char oprtrs[][6]);
double do_math(char oprtrs[][6], int o_end, double* nums, int n_end, char ops[][6], char string_out[], char error_out[]);

int main()
{
    char string[256] = {'\0'};
    int operators[256] = {'\0'};        // receiving output of tokenize
    char oprtrs[256][6] = {'\0'};       // to compare with user input
    double numbers[256] = {'\0'};
    char string_out[256] = {'\0'};
    char error_out[256] = {'\0'};
    double result = 0;

    defining_ops();

    start_message();
    while (1) {

        gets(string);
        // set the cursor position to the end of the input line
        set_cursor_pos(strlen(string) + 1, get_cursor_y() - 1);
        // getting operators from 'string'
        remove_spaces(string);
        // printf("%s\n", string);
        get_int_array(operators, string, "1234567890");
        // converting int array of operators to char array (int* operators, char** oprtrs)
        int_to_char_2d_array(operators, oprtrs);
        // getting numbers from 'string'
        get_double_array(numbers, string, "+-/*%^<logbintohextodectoexitclearhelp");

        switch(input_count(oprtrs, ops)) {
        case -1:
            print_error("Wrong input. Please try again.\n");
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (char2d_arr_len(oprtrs) +1 != double_arr_len(numbers)) {
                strcat(error_out, "Wrong use of operators.");
                goto on_error;
            }
            goto on_default;
        case 11:
            return 0;
            break;
        case 12:
            clear();
            break;
        case 13:
            start_message();
            break;
        default:
            on_default:
            result = do_math(oprtrs, char2d_arr_len(oprtrs) - 1, numbers, double_arr_len(numbers) - 1, ops, string_out, error_out);
            if(result != DBL_MAX)
                print_num_result(result);
            else if (strlen(string_out) > 1)
                print_str_result(string_out);
            else {
                on_error:
                print_error(error_out);
            }
            break;
        }

        clear_database(string, operators, oprtrs, numbers, result, string_out, error_out);

    }

    return 0;
}


