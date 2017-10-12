#include <stdint.h>
#include <stdio.h>

int main() {
	// print the even numbers till 20
    uint8_t a = 20;
    uint8_t x = 0;

    while (x <= a)
    {
        printf("%d\n", x);
        x += 2;

    }

    printf("\n\n");
    x = 0;

    do
    {
        printf("%d\n", x);
        x += 2;

    }while(x <= a);

    printf("\n\n");

    for(uint8_t i; i <= a; i += 2)
    {
        printf("%d\n", i);
    }



	return 0;
}
