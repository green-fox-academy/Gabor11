#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void start_message();
int* tokenize(char* string, char s[12]);
int int_pnt_len(int* array);
void set_cursor_pos(int x, int y);

COORD coord = {0,0};

int main()
{

    char string[256] = {'\0'};
    int operators[256] = {'\0'};
    int numbers[256] = {'\0'};
    int* val;
    start_message();

    gets(string);
    // getting operators from 'string'
    val = tokenize(string, "1234567890");
    for (int i = 0; i < int_pnt_len(val); i++) {
        operators[i] = val[i];
    }
    // getting numbers from 'string'
    val = tokenize(string, "+-/*");
    for (int i = 0; i < int_pnt_len(val); i++) {
        numbers[i] = val[i];
    }

    for (int i = 0; i < int_pnt_len(operators); i++) {
        printf("%d\n", operators[i]);
    }

    printf("\n");

    for (int i = 0; i < int_pnt_len(numbers); i++) {
        printf("%d\n", numbers[i]);
    }


    return 0;
}

void start_message()
{
    printf("Welcome!\n\tCLI Calculator\n\
====================================\n\
usage: [number] [operation] [number]\n\
Commands:\n\
\n\
+\tsummation\n\
-\tsubtraction\n\
*\tmultiplication\n\
/\tdivision\n\
%\tdivision with remainder\n\
^\tsquaring\n\
<\tsquare root\n\
log\tlogarithm\n\
log\tlogarithm\n\
hexto\thexadecimal to bin or dec\n\
decto\tdecimal to bin or hex\n\
====================================\n\
exit\texiting from the program\n\
clear\tclear the screen\n\
help\tprint usage\n\
====================================\n\
Hit enter to start!\n\
====================================\n");
}

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

int int_pnt_len(int* array)
{
    int i = 0;
    while (array[i] != NULL) {
        i++;
    }
    return i;
}

void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
