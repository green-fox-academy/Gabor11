#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <windows.h>


void print_num_result(double val)
{
    printf("= %g\n", val);
}

void print_str_result(char* string_out)
{
    printf("= %s\n", string_out);
}

void print_error(char* val)
{
    printf("= %s\n", val);
}

void clear()
{
    system("cls");
}

void start_message()
{
    clear();
    char c = 0;

    printf("\n\tCLI Calculator\n\
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
<\tnth root\n\
log\tlogarithm\n\
tobin\tdec to bin\n\
tohex\tdec to hexadecimal\n\
====================================\n\
exit\texiting from the program\n\
clear\tclear the screen\n\
help\tprint usage\n\
====================================\n\
Hit enter to start!\n\
====================================\n");

    while (c != 13) {
        c = getch();
    }
    clear();
}

int input_count(char oprtrs[][6], char ops[][6])
{

    int len = char2d_arr_len(oprtrs);
    int count = 0;

    for (int i = 0 ; i < 8 ; i++) {
        for (int j = 0 ; j < len ; j++) {
            if (strcmp(oprtrs[j],ops[i]) == 0) {
                count++;
            }
        }
    }


    for (int i = 8 ; i < 14 ; i++) {
        for (int j = 0 ; j < len ; j++) {
            if (strcmp(oprtrs[j],ops[i]) == 0) {
                return i;
            }
        }
    }
    // if all operators are known it is good :)
    if (count == len)
        return 15;
    else
        return -1;

}

COORD coord = {0,0};

void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int get_cursor_y()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    return csbi.dwCursorPosition.Y;
}
