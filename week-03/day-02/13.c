#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";
    char *first, *last;

	//TODO: write a program which prints out the distance between the first and last occurance of character 's'
	first = strchr(str, 's');
	last = strrchr(str, 's');

	printf("%s\n", str);
	printf("And the distance between the first and last occurance: \n");
	printf("%d", last - first);

    return 0;
}
