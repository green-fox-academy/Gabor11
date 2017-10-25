#include <stdio.h>
#include <stdint.h>

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

int main() {
    struct Computer computer = {3.2, 8, 32};

    //TODO: Change the bits to 64

    computer.bits = 64;

    //TODO: print out the structure members

    print_Computer(computer);

    return 0;
}

void print_Computer(struct Computer comp)
{
    printf("cpu speed [GHz]:\t %.2f\n", comp.cpu_speed_GHz);
    printf("ram size [GB]:\t\t %d\n", comp.ram_size_GB);
    printf("bits:\t\t\t %d\n", comp.bits);
}
