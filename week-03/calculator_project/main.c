#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "tokenize.h"
#include "start_message.h"
#include "int_pnt_len.h"
#include "get_array.h"
#include "operators.h"

void start_message(); // outsourced
int* tokenize(char* string, char s[12]); // outsourced
int int_pnt_len(int* array);
void set_cursor_pos(int x, int y);
void get_array(int* target_array, char* string, char* filter);
float do_math(int* ops, int o_end, int* nums, int n_end);


COORD coord = {0,0};

int main()
{
    char string[256] = {'\0'};
    int operators[256] = {'\0'};        // receiving output of tokenize
    char *oprtrs[256] = {'\0'};         // to compare with user input
    int numbers[256] = {'\0'};
    float result = 0;
    int j = 0;
    int k = 0;
    char* buffer = malloc(sizeof(char) * 10);
    // char buffer[10] = {'\0'};

    operators[0] = 43;
    operators[1] = 1;
    operators[2] = 45;
    operators[3] = 1;

    oprtrs[0] = "valami";
    oprtrs[1] = "valami";
    oprtrs[2] = "valami";

    // filling up oprtrs
    for (int i = 0; i < int_pnt_len(operators); i++) {
        while(operators[i] != 1) {
            buffer[k] = operators[i];
            k++;
            i++;
        }
        buffer[k] = '\0';
        // oprtrs[j] = malloc(sizeof(char) * 11);
        memmove(oprtrs[j], buffer, int_pnt_len(buffer));
        j++;
        k = 0;
    }

    defining_ops();

    for (int i = 0; i < 3; i++) {
        printf("%s\n", oprtrs[i]);
    }
/*
    defining_ops();
    start_message();

    gets(string);
    // getting operators from 'string'
    get_array(operators, string, "1234567890");
    // getting numbers from 'string'
    get_array(numbers, string, "+-/*");

    result = do_math(operators, int_pnt_len(operators) - 1, numbers, int_pnt_len(numbers) - 1);

    printf("%f\n\n\n", result);

    for (int i = 0; i < int_pnt_len(operators); i++) {
        printf("%d\n", operators[i]);
    }

    printf("\n");

    for (int i = 0; i < int_pnt_len(numbers); i++) {
        printf("%d\n", numbers[i]);
    }

/**/
    return 0;
}


// this function receives the end of the two arrays and it iterates through them recursively
float do_math(int* ops, int o_end, int* nums, int n_end)
{
    float result = 0;
    if (ops[o_end - 1] != NULL)
        result = do_math(ops, o_end - 1, nums, n_end - 1);
    else
        result = nums[n_end - 2];
    // choosing the operator
    if (ops[0] == '+')
            return result + nums[n_end - 1];


}

/*int* get_operators(int* operators)
{
    int* values;        // values to return
    char *ops[14];      // the operation set
    int i = 0;          // iteration variable
    int count = 0;

    char *add_ = "+";
    char *sub_ = "-";
    char *mul_ = "*";
    char *div_ = "/";
    char *mod_ = "%";
    char *pow_ = "^";
    char *sqr_ = "<";
    char *log_ = "log";
    char *binto_ = "binto";
    char *hexto_ = "hexto";
    char *decto_ = "decto";
    char *exit_ = "exit";
    char *clr_ = "clear";
    char *help_ = "help";

    ops[0] = add_;
    ops[1] = sub_;
    ops[2] = mul_;
    ops[3] = div_;
    ops[4] = mod_;
    ops[5] = pow_;
    ops[6] = sqr_;
    ops[7] = log_;
    ops[8] = binto_;
    ops[9] = hexto_;
    ops[10] = decto_;
    ops[11] = exit_;
    ops[12] = clr_;
    ops[13] = help_;

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
