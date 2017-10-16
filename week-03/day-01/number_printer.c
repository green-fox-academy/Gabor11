#include <stdio.h>
#include <stdlib.h>

// debugging workshop

void printf_numbers(int from, int to)
{
	for (int i = from; i < to; i++)
		printf("%d,", i);
}

int main()
{
    // function name: fprintf_numbers -> printf_numbers
    // function parameters: from = 2147483600 -> 2147482600, to = 2147484600 -> 2147483600
	printf_numbers(2147482600, 2147483600);
	return 0;
}
