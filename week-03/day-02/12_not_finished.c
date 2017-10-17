#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] = "This is a string for testing";
	char target[55] = {'\0'};
	char *p;
    int index;
    int size = strlen(string);

	//TODO: write a program, which lists all position where character 'i' is found
      //  p = strchr(string, 'i');
      //  index = (int)(p - string);
      //  printf("%d\n", index);
        strncat(target, string, size - 1);
        printf("%s\n", target);

	return 0;
}
