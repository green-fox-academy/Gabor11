#include <stdio.h>
#include <stdlib.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 57548;
    int number_of_banknotes;
    int banknote;

    printf("payment of %d HUF can be paid:\n", amount_of_money);

    //taking care of rounding
    switch (amount_of_money%10)
    {
    case 1:
        amount_of_money = amount_of_money - 1;
        break;
    case 2:
        amount_of_money = amount_of_money - 2;
        break;
    case 3:
        amount_of_money = amount_of_money + 2;
        break;
    case 4:
        amount_of_money = amount_of_money + 1;
        break;
    case 6:
        amount_of_money = amount_of_money - 1;
        break;
    case 7:
        amount_of_money = amount_of_money - 2;
        break;
    case 8:
        amount_of_money = amount_of_money + 2;
        break;
    case 9:
        amount_of_money = amount_of_money + 1;
        break;
    default:
        break;
    }


    // count pieces of banknotes
    for (int i =0; i <12; i++)
    {
        switch (i)
        {
        case 0:
            banknote = 20000;
            break;
        case 1:
            banknote = 10000;
            break;
        case 2:
            banknote = 5000;
            break;
        case 3:
            banknote = 2000;
            break;
        case 4:
            banknote = 1000;
            break;
        case 5:
            banknote = 500;
            break;
        case 6:
            banknote = 200;
            break;
        case 7:
            banknote = 100;
            break;
        case 8:
            banknote = 50;
            break;
        case 9:
            banknote = 20;
            break;
        case 10:
            banknote = 10;
            break;
        case 11:
            banknote = 5;
            break;
        default:
            banknote = 0;

        }
        number_of_banknotes = amount_of_money/banknote;
        amount_of_money = amount_of_money%banknote;
        if (number_of_banknotes != 0)
        printf("%d * %d\n",number_of_banknotes, banknote);
    }


    return 0;
}
