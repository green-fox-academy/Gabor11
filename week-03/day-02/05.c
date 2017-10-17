#include <stdio.h>
#include <string.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use

unsigned int func_485();

int main()
{
    // actually there is no need to cast it explicitly
    // because the value "485" can be represented straight forward as an integer
    int a = 229;
    a = func_485();
    printf("%d\n", a);


    return 0;
}

unsigned int func_485()
{
    return 485;
}
