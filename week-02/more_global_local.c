#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tom, Mark and Jerry went to the supermarket
//help them decide what can they buy out of their money

int tom_money = 2000;
int mark_money = 3500;
int jerry_money = 1200;

void can_they_buy_a_new_tv()
{
    int tv_price = 6950;

    //if they can, the program should write out that how much
    //money they have after they bought the tv
    //if they can't tell, how much money they need to buy it
    int diff = (tom_money + mark_money + jerry_money) - tv_price;
    if ( diff > 0){
        printf("If they buy the tv they will have %d dollars left.\n", diff);
    } else {
        printf("They cannot buy the tv.\n");
    }

}

void can_they_make_a_cake()
{
    int milk = 200;
    int chocolate = 340;
    int flour = 75;
    int egg = 345;
    int sugar = 160;
    int salt = 90;
    int oven_shape = 330;
    int cream = 220;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally

    int sum = milk + chocolate + flour + egg + sugar + salt + oven_shape + cream;
    int diff = (tom_money + mark_money + jerry_money) - sum;

    if (diff > 0) {
        printf("If they want to pay all the ingredients of this cake equally they need to pay %d dollars each.\n", sum / 3);
    } else {
        printf("They cannot pay for all these stuff.\n");
    }
}

void can_they_make_ham_and_eggs()
{
    int milk = 200;
    int egg = 345;
    int salt = 90;
    int ham = 450;
    int onion = 60;
    int spice = 25;

    //if they can buy all these stuff calculate how much
    //each of them should pay to share the bill equally
    int sum = milk + egg + salt + ham + onion + spice;
    int diff = (tom_money + mark_money + jerry_money) - sum;

    if (diff > 0) {
        printf("If they want to pay all the ingredients of ham and eggs equally they need to pay %d dollars each.\n", sum / 3);
    } else {
        printf("They cannot pay for all these stuff.\n");
    }
}

//is there any local or global variables we did not use well? --> I suppose many ingredients could be used as global outside the scope of the function using them
//are we using functions correctly? --> I overwrote the "int" returning types to "void" because there was no need to return anything..

int main()
{
    can_they_buy_a_new_tv();
    can_they_make_ham_and_eggs();
    can_they_make_a_cake();

	return 0;

}
