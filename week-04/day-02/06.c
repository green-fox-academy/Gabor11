#include <stdio.h>
#include <stdlib.h>

struct Pirate {
    char name[256];
    int has_wooden_leg;
    short int gold_count;
};

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the sum of the golds of all pirates

int sum_gold(struct Pirate* pir_array, int num_of_pirates)
{
    int sum = 0;

    for (int i = 0; i < num_of_pirates; i++) {
        sum += pir_array[i].gold_count;
    }

    return sum;
}

// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the average of the gold / pirate

double avg_gold(struct Pirate* pir_array, int num_of_pirates)
{
    int sum = 0;

    for (int i = 0; i < num_of_pirates; i++) {
        sum += pir_array[i].gold_count;
    }

    return (double)sum / num_of_pirates;
}
// TODO:
// Create a function that takes an array of pirates (and it's length) then returns the name of the
// richest that has wooden leg

char *richest_wooden_leg(struct Pirate* pirates, int num_of_pirates)
{
    struct Pirate *r_w_l = malloc(sizeof(pirates[0]));
    (*r_w_l) = pirates[0];
    for (int i = 1; i < num_of_pirates; i++) {
        if (!(*r_w_l).has_wooden_leg) {
            *r_w_l = pirates[i];
            i++;
        }
        if (pirates[i].gold_count > (*r_w_l).gold_count && pirates[i].has_wooden_leg == 1)
            *r_w_l = pirates[i];
    }

    return (*r_w_l).name;
}

int main() {
    struct Pirate pirates[] = {
        {"Jack", 0, 18},
        {"Uwe", 1, 8},
        {"Hook", 1, 12},
        {"Halloween kid", 0, 0},
        {"Sea Wolf", 1, 14},
        {"Morgan", 0, 1}
    };

    printf("The sum of the gold of the pirates: %d\n", sum_gold(pirates, 6));
    printf("The average gold of the pirates: %.2f\n", avg_gold(pirates, 6));
    printf("The richest wooden leg pirate: %s\n", richest_wooden_leg(pirates, 6));
    return 0;
}
