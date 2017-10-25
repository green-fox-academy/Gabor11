#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

int main() {

    struct Car car;
    car.type = VOLVO;

    print_car(car);

  return 0;
}

void print_car(struct Car car)
{
    switch(car.type) {
    case TESLA:
        printf("Type: Tesla\n");
        printf("km: %.2f\n", car.km);
        break;
    case LAND_ROVER:
        printf("Type: Land Rover\n");
        printf("km: %.2f\n", car.km);
        printf("gas: %.2f\n", car.gas);
        break;
    case TOYOTA:
        printf("Type: Toyota\n");
        printf("km: %.2f\n", car.km);
        printf("gas: %.2f\n", car.gas);
        break;
    case VOLVO:
        printf("Type: Volvo\n");
        printf("km: %.2f\n", car.km);
        printf("gas: %.2f\n", car.gas);
        break;
    default:
        break;
    }
}
