#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t number = 254;
	// if number can't be represented with 8bits
	// print 'longer than 8bits' otherwise print 'ok'

	/*uint8_t number8;
	number8 = number;

	if (number8 == number) { printf("The number can be represented in 8 bits");} else {printf("The number cannot be represented in 8 bits");}
    */

    if (number < 256) {printf("The number can be represented in 8 bits");} else {printf("The number cannot be represented in 8 bits");}

	return 0;
}
