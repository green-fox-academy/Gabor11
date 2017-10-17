#include <stdio.h>
#include <string.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];
    const char s[2] = " ";
    char *token;

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function

	gets(string);

	token = strtok(string, s);

    while(token != NULL) {
        printf( "%s\n", token);
        token = strtok(NULL, s);
    }
    return 0;
}
