#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";

	//TODO: implement your own strlen function.
    printf("my_strlen: \t%d\n", my_strlen(my_string));
    printf("strlen: \t%d\n", strlen(my_string));


	return 0;
}

int my_strlen(char *string)
{
    int i = 0;
    while(string[i] != '\0') {
        i++;
    }
    return i;
}
