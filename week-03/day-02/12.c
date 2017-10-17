#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] = "This is a string for testing";
	char* target = {'\0'};

	//TODO: write a program, which lists all position where character 'i' is found

    target = string;
    while (target != NULL) {
        target = strchr(target, 'i');
        if (target != NULL) {
            printf("%d\n", (int)(target - string));
            target++;
        }
    }

	return 0;
}
