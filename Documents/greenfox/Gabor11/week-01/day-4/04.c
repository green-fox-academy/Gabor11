#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ae = 4;
	// print "yeeeeeeeey" ae times
	uint8_t x = 0;

    while (x <= ae)
    {
        printf("yeeeeeeeey\n", x);
        x++;
    }

    printf("\n\n");
    x = 0;

    do
    {
        printf("yeeeeeeeey\n", x);
        x++;
    }while(x <= ae);

    printf("\n\n");

    for(int8_t i; i <= ae; i++)
    {
        printf("yeeeeeeeey\n", i);
    }

	return 0;
}
