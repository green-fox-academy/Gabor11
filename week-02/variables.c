#include <stdio.h>

/*
Write a program where you have five functions
first the program should ask for an integer, then
these functions should do various mathematical operations on a given integer
last but not least there should be a variable which counts how many operations
have been done on the given integer
*/

int add_2(int input);
int multiply_by_2(int input);
int substract_2(int input);
int devide_integer_by_4(int input);
int modulo_5(int input);
int op_count = 0;

int main()
{
    int input_ = 0;
    printf("Pls give me an integer:\n");
    scanf("%d\n", &input_);

    printf("%d\n",input_);

    // printf("And the result: %d\n", modulo_5(devide_integer_by_4(substract_2(multiply_by_2(add_2(input_))))));

    return 0;
}

int add_2(int input){
    return input + 2;
    op_count++;
    }
int multiply_by_2(int input){
    return input *2;
    op_count++;
    }
int substract_2(int input){
    return input - 2;
    op_count++;
    }
int devide_integer_by_4(int input){
    return input / 4;
    op_count++;
    }
int modulo_5(int input){
    return input % 5;
    op_count++;
    }

