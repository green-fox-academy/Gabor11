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
