#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf
        printf("%d\n",result);
 	// What happened?!

        // "uint8_t result" canNOT hold a bigger number then 255 so the variable overflows.

	// Try again with different datatype
	uint16_t result_16 = number + 23;
	// Check the result with printf
        printf("%d\n",result_16);
	// What happened and why?

		// "uint16_t result_16" can hold a bigger number then 255 so the variable does not overflow but stores the result :).

	//----------------------------------------
	int8_t number_negative = number;
	// Check the result with printf
        printf("%d\n",number_negative);
	// What happened and why?

        // the variable overflows.

    return 0;
}
