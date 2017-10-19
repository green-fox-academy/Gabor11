#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tokenize.h"
#include "start_message.h"
#include "arr_len.h"
#include "get_array.h"
#include "operators.h"

void start_message(); // outsourced
double* tokenize(char* string, char s[12]); // outsourced
char* remove_spaces(char* input);
int double_arr_len(double* array);
void set_cursor_pos(int x, int y);
void get_double_array(double* target_array, char* string, char* filter);
void get_int_array(int* target_array, char* string, char* filter);
void int_to_char_2d_array(int* operators, char oprtrs[][6]);
double do_math(char oprtrs[][6], int o_end, double* nums, int n_end);


COORD coord = {0,0};

int main()
{
    char string[256] = {'\0'};
    int operators[256] = {'\0'};        // receiving output of tokenize
    char oprtrs[256][6] = {'\0'};         // to compare with user input
    double numbers[256] = {'\0'};
    double result = 0;
    /*
    operators[0] = 43;
    operators[1] = 44;
    operators[2] = 45;
    operators[3] = 1;

    strcpy(oprtrs[0], "valam");
    strcpy(oprtrs[1], "valam");
    strcpy(oprtrs[2], "valam");



    for (int i = 0; i < 3; i++) {
        printf("%s\n", oprtrs[i]);
    }
/**/
    defining_ops();
    start_message();

    gets(string);
    // getting operators from 'string'
    remove_spaces(string);
    // printf("%s\n", string);
    get_int_array(operators, string, "1234567890");
    // converting int array of operators to char array (int* operators, char** oprtrs)
    int_to_char_2d_array(operators, oprtrs);
    // getting numbers from 'string'
    get_double_array(numbers, string, "+-/*%^<logbintohextodectoexitclearhelp");

   /* result = do_math(operators, double_arr_len(operators) - 1, numbers, double_arr_len(numbers) - 1);

    printf("%f\n\n\n", result);
    /**/
    for (int i = 0; i < char2d_arr_len(oprtrs); i++) {
        printf("%s\n", oprtrs[i]);
    }

    printf("\n");

    for (int i = 0; i < double_arr_len(numbers); i++) {
        printf("%f\n", numbers[i]);
    }

/**/
    return 0;
}


// this function receives the end of the two arrays and it iterates through them recursively
double do_math(char oprtrs[][6], int o_end, double* nums, int n_end)
{
    float result = 0;
    if (oprtrs[o_end - 1] != NULL)
        result = do_math(ops, o_end - 1, nums, n_end - 1);
    else
        result = nums[n_end - 2];
    // choosing the operator
    if (oprtrs[0] == '+')
            return result + nums[n_end - 1];


}

/*int* get_operators(int* operators)
{

    // dealing with comparison of input and the given operator set
    // and filling up the actual operator array
    while (operators[i] != NULL) {
        for (int j = 0; j < 14; j++) {
            for (int k = 0; k < strlen(ops[j]); k++) {
                if (ops[j][k] == operators[i]) {
                    count++;
                    i++;
                    // in case we would run out of values of 'operators' it breaks out the whole loops
                    if (operators[i] == NULL) {
                        k = strlen(ops[j]);
                        j = 14;
                        break;
                    }
                } else if (operators[i] == 1 && ) {
                    break;
                } else if (count == strlen(ops[j])){

                }
            }
        }

    }

} */

void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
