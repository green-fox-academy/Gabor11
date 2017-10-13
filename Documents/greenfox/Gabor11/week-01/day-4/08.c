#include <stdio.h>
#include <stdlib.h>


/*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/

int main()
{

    int num = 0;

    while (num <= 100)
    {
        switch (num % 2)
        {
        case 0:
            printf("even\n");
            break;
        case 1:
            printf("odd\n");
            break;
        }
        num++;
    }

    return 0;
}
