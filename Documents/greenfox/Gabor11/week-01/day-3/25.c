#include <stdio.h>
#include <stdlib.h>

/*
write a program to find the largest number of three
*/

int main()
{
    int a = 13;
    int b = 29;
    int c = 7;
    int max;

    if (a > b) {max = a;} else { max = b;}
    if (c > max) {max = c;}

    printf("Out of these three number %d is the largest.", max);

    return 0;


}
