#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t ad = 6;
	uint8_t x = 0;
	// print the numbers till ad from 0

	while (x <= ad)
    {
        printf("%d\n", x);
        x++;
    }

    printf("\n\n");
    x = 0;

    do
    {
        printf("%d\n", x);
        x++;
    }while(x <= ad);

    printf("\n\n");

    for(int8_t i; i <= ad; i++)
    {
        printf("%d\n", i);
    }
	return 0;
}
