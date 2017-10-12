#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 3243;
    printf("%d days are:\n", days);
    int years = days / 365;
    days = days % 365;
    int months = days / 30;
    days = days % 30;
    int weeks =  days / 7;
    days = days % 7;

    printf("%d years, %d months, %d weeks and %d days.\n",years, months, weeks, days);




    return 0;
}
