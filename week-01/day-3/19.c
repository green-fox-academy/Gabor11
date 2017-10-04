#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;
	// Tell if the reminder of b devided by a is 3
    printf("%d\n", b%a);
	printf("%s",(b%a == 3 ? "true" : "false"));

	return 0;
}
