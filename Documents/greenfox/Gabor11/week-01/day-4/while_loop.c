#include <stdio.h>
#include <stdlib.h>

int main()
{
    int day =1;
    float amount = .01;

    while (day <= 31)
    {
        amount *= 2;
        printf("Day: %d  \tamount: %.2f\n", day, amount);
        day++;
    }

    return 0;
}
