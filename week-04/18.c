#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first_word(char *string, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "Extracting the first word.";
    char first[50];

    printf("length of first word: %d\n", first_word(str, first));
    printf("%s\n", first);

    return 0;
}

int first_word(char str[], char *first)
{
    static char *token;

    token = strtok(str, " ");

    printf("%s", token);

    first = token;
   // if(token != NULL)
    return strlen(token);

    //return 0;

}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first_word(char *string, char *first);

int main()
{
    //TODO: write a function, which extracts the first word of a given string.
    //return with the word's length

    char str[] = "Extracting the first word.";
    char first[50];

    printf("length of first word: %d\n", first_word(str, first));
    printf("%s\n", first);

    return 0;
}

int first_word(char str[], char *first)
{
    static char *token;

    token = strtok(str, " ");

    printf("%s", token);

    first = token;
   // if(token != NULL)
    return strlen(token);

    //return 0;

}
