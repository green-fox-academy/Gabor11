#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int* tokenize(char* string, char s[12])
{
    // making a new char array to keep the initial string unchanged
    char* tempstr = calloc(strlen(string) + 1, sizeof(char));
    strcpy(tempstr, string);
    char* token;
    static int values[30] = {'\0'};
    int i = 0;

    // starting to process the string
    token = strtok(tempstr, s);

    while(token != NULL) {
        // dealing with operators
        if (atoi(token) == NULL) {
            for (int j = 0; j < strlen(token); j++) {
                values[i] = token[j];
                i++;
            }
            values[i] = 1;
            i++;
            token = strtok(NULL, s);
        } else { // dealing with numbers
        //printf( "%s\n", token);
        values[i] = atoi(token);
        token = strtok(NULL, s);
        i++;
        }
    }
    values[i] = '\0';
    return values;
}

char* remove_spaces(char* input)                                 /* deblank accepts a char[] argument and returns a char[] */
{
    int i, j;
    i = j = 0;
    char *output = input;
    for (i, j ; i < strlen(input) ; i++, j++)          /* Evaluate each character in the input */
    {
        if (input[i]!=' ')                                       /* If the character is not a space */
            output[j]=input[i];                                  /* Copy that character to the output char[] */
        else
            j--;                                                  /* If it is a space then do not increment the output index (j), the next non-space will be entered at the current index */
    }
    output[j] = '\0';
    return output;                                                /* Return output char[]. Should have no spaces*/
}
