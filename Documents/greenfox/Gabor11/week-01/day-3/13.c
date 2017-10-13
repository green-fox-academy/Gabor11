#include <stdio.h>
#include <stdint.h>

#define BTB_PATTERN "%c%c%c%c%c%c%c%c"
#define BTB(uint8_t)  \
  (uint8_t & 0x80 ? '1' : '0'), \
  (uint8_t & 0x40 ? '1' : '0'), \
  (uint8_t & 0x20 ? '1' : '0'), \
  (uint8_t & 0x10 ? '1' : '0'), \
  (uint8_t & 0x08 ? '1' : '0'), \
  (uint8_t & 0x04 ? '1' : '0'), \
  (uint8_t & 0x02 ? '1' : '0'), \
  (uint8_t & 0x01 ? '1' : '0')

int main() {
    uint8_t x = 0b11001100;
    uint8_t y = 0b01010101;
	uint8_t z;

	// Be z equal to the bitwise and of x and y

	z = x & y;

	// Check the result with printf

	printf("%d \n%d \n%d \n", x, y, z);
	printf("\n"BTB_PATTERN,BTB(x));
	printf("\n"BTB_PATTERN,BTB(y));
	printf("\n"BTB_PATTERN,BTB(z));
	printf("\n");
	printf("\n");

	// Be z equal to the bitwise or of x and y

	z = x | y;

	// Check the result with printf

	printf("%d \n%d \n%d \n", x, y, z);
	printf("\n"BTB_PATTERN,BTB(x));
	printf("\n"BTB_PATTERN,BTB(y));
	printf("\n"BTB_PATTERN,BTB(z));
    printf("\n");
    return 0;
}
