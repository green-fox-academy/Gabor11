#include <stdio.h>
#include <string.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
typedef struct {
    char address[255];
    int price;
    int num_rooms;
    double area;

} House;
// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)

int worth_to_buy(House *house_ptr)
{
    int market_price = 400;
        if ((*house_ptr).area * market_price > (*house_ptr).price)
            return 1;
    return 0;
}

// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.

int houses_to_buy(House houses[], int num_of_houses)
{
    int count = 0;
    for (int i = 0; i < num_of_houses; i++) {
        if (worth_to_buy(&houses[i])) {
            count++;
        }
    }

    return count;
}

int main() {

    House houses[15];
    for (int i = 0; i < 15; i++) {
        House h;
        strcpy(h.address, "somewhere");
        h.area = 10 + 20 * i;
        h.num_rooms = i % 5;
        h.price = 2000 + i * 8500;

        houses[i] = h;
        printf("%d: area: %.f, price: %d, price/squaremeter: %.2f\n", i, h.area, h.price, h.price/h.area);
    }

    printf("Houses to buy: %d\n", houses_to_buy(houses, 15));

  return 0;
}
