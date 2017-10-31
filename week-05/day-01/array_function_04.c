#include <stdio.h>
#include <stdlib.h>
#include "rlutil.h"

// including "rlutil.h" is needed!!!

/*
 * Create a representation of a chess board in the form of a two dimensional character array.
 * Each figure should have a character representing it. Empty places should be a single space: ' '.
 *
 * Create a function which sets up the board.
 *
 * Create a function for checking the moves for each of the figures. They should get coordinates for the figure and where to move it.
 * They should return 0 if the move is acceptable in chess and -1 if not.
 *
 * Create a function which moves figures by getting the initial coordinate and the target coordinate.
 * This should return -1 if the move was not successful and 0 if all is right and if all is right then also move the figure.
 *
 * Determine what kind of arguments You need for the functions. Write them accordingly.
 *
 * For the sake of this exercise it's enough if You write the specific functions for pawn and knight.
 *
 * In the main functions set up the board and try them. Check if they work as intended.
*/

int move_checker(char chessboard[8][8], int x, int y, int xx, int yy);
int move_figure(char chessboard[8][8], int x, int y, int xx, int yy);
int set_up_board(char chessboard[8][8]);
void print_board(char chessboard[8][8]);
int get_coord(char *text, char input[5], int *x, int *y);
void set_cursor_pos(int x, int y);
int get_cursor_y();
void clear();

COORD coord = {0,0};

int main()
{
    char chessboard[8][8] = {'\0'};
    int x, y, xx, yy;
    char c = 0;
    char input1[5];
    char input2[5];
    saveDefaultColor();

    set_up_board(chessboard);
    while(1) {
        c = 0;
        set_cursor_pos(0, 0);
        print_board(chessboard);
        if (get_coord("from>", input1, &x, &y) != 0) {
            puts("please use correct coordinates\n");
            resetColor();
            while (c != 13) {
            c = getch();
            }
            clear();
            continue;
        }
        if (get_coord("  to>", input2, &xx, &yy) != 0) {
            puts("please use correct coordinates\n");
            resetColor();
            while (c != 13) {
            c = getch();
            }
            clear();
            continue;
        }
        if (move_checker(chessboard, x, y, xx, yy) == 0) {
            move_figure(chessboard, x, y, xx, yy);
            printf("valid step\n");
        } else {
            printf("invalid step\n");
            while (c != 13) {
            c = getch();
            }
        }
        resetColor();
        clear();

    }

}

int set_up_board(char chessboard[8][8])
{
    //setting up pawns and spaces:
    for (int i = 0; i < 8; i++) {
        chessboard[1][i] = 'p';
        chessboard[2][i] = ' ';
        chessboard[3][i] = ' ';
        chessboard[4][i] = ' ';
        chessboard[5][i] = ' ';
        chessboard[6][i] = 'P';
    }

    //black figures:
    chessboard[0][0] = 'r';
    chessboard[0][1] = 'h';
    chessboard[0][2] = 'b';
    chessboard[0][3] = 'q';
    chessboard[0][4] = 'k';
    chessboard[0][5] = 'b';
    chessboard[0][6] = 'h';
    chessboard[0][7] = 'r';

    //white figures:
    chessboard[7][0] = 'R';
    chessboard[7][1] = 'H';
    chessboard[7][2] = 'B';
    chessboard[7][3] = 'Q';
    chessboard[7][4] = 'K';
    chessboard[7][5] = 'B';
    chessboard[7][6] = 'H';
    chessboard[7][7] = 'R';
}

int move_checker(char chessboard[8][8], int x, int y, int xx, int yy)
{
    int i = 0;
    int j = 0;
    char switcher = chessboard[x][y];

    switch (switcher) {
    case 'P':
        if (x - xx == 1 && y - yy == 0 && chessboard[xx][yy] == ' ') //while moving one step forward normally
            return 0;
        else if (x - xx == 1 && abs(y - yy) == 1 && chessboard[xx][yy] > 96)    //while hitting a figure from the opponent
            return 0;
        else if (xx == 4 && x == 6 && y - yy == 0 && chessboard[xx][yy] == ' ' && chessboard[xx + 1][yy] == ' ')  //while moving 2 steps from the start-line
            return 0;
        else
            return -1;
        break;
    case 'R':
        // checking whether vertically backwards there are something in the way
        // or if an opponent figure stands on the target field (> 96 means lower case character --> opponent)
        if (x - xx < 0 && y - yy == 0) {
            for (i = x + 1; i < xx; i++) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether vertically upwards there are something in the way
        if (x - xx > 0 && y - yy == 0) {
            for (i = x - 1; i > xx; i--) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally leftwards there are something in the way
        if (x - xx == 0 && y - yy > 0) {
            for (i = y - 1; i > yy; i--) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally rightwards there are something in the way
        if (x - xx == 0 && y - yy < 0) {
            for (i = y + 1; i < yy; i++) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'H':
        if ((abs(x - xx) == 1 && abs(y - yy) == 2 && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' ')) || (abs(x - xx) == 2 && abs(y - yy) == 1 && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' ')))
            return 0;
        else
            return -1;
        break;
    case 'B':
        // BISHOP: it must be checked whether there is some figure in the way or not
        // hitting an opponent at the very end is permitted
        // left - up
        if (x - xx == y - yy && x - xx > 0) {
            for (i = x - 1, j = y - 1; i > xx; i--, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - down
        if (x - xx == y - yy && x - xx < 0) {
            for (i = x + 1, j = y + 1; i < xx; i++, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - up
        if (x - xx == yy - y && y - yy < 0) {
            for (i = x - 1, j = y + 1; i > xx; i--, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // left - down
        if (xx - x == y - yy && x - xx < 0) {
            for (i = x + 1, j = y - 1; i < xx; i++, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'Q':
        // ROOK-like behavior:
        // checking whether vertically backwards there are something in the way
        // or if an opponent figure stands on the target field (> 96 means lower case character --> opponent)
        if (x - xx < 0 && y - yy == 0) {
            for (i = x + 1; i < xx; i++) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether vertically upwards there are something in the way
        if (x - xx > 0 && y - yy == 0) {
            for (i = x - 1; i > xx; i--) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally leftwards there are something in the way
        if (x - xx == 0 && y - yy > 0) {
            for (i = y - 1; i > yy; i--) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally rightwards there are something in the way
        if (x - xx == 0 && y - yy < 0) {
            for (i = y + 1; i < yy; i++) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // BISHOP-like behavior:
        // it must be checked whether there is some figure in the way or not
        // hitting an opponent at the very end is permitted
        // left - up
        if (x - xx == y - yy && x - xx > 0) {
            for (i = x - 1, j = y - 1; i > xx; i--, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - down
        if (x - xx == y - yy && x - xx < 0) {
            for (i = x + 1, j = y + 1; i < xx; i++, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - up
        if (x - xx == yy - y && y - yy < 0) {
            for (i = x - 1, j = y + 1; i > xx; i--, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // left - down
        if (xx - x == y - yy && x - xx < 0) {
            for (i = x + 1, j = y - 1; i < xx; i++, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'K':
        if (abs(x - xx) == 1 && (abs(y - yy) == 1 || y - yy == 0) && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' ')) //while moving one step vertically or aside
            return 0;
        else if (x - xx == 0 && abs(y - yy) == 1 && (chessboard[xx][yy] > 96 || chessboard[xx][yy] == ' ')) // while moving one step to the left or to the right
            return 0;
        // castling
        else if (x == 7 && y == 4 && xx == 7 && yy == 6) {
            for (i = y + 1; i < yy; i++) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && chessboard[xx][yy] == ' ' && chessboard[7][7] == 'R')
                return 0;
        } else {
            return -1;
        }
        break;

    case 'p':
        if (x - xx == -1 && y - yy == 0 && chessboard[xx][yy] == ' ') //while moving one step forward normally
            return 0;
        else if (x - xx == -1 && abs(y - yy) == 1 && chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64)    //while hitting a figure from the opponent
            return 0;
        else if (xx == 3 && x == 1 && y - yy == 0 && chessboard[xx][yy] == ' ' && chessboard[xx - 1][yy] == ' ')  //while moving 2 steps from the start-line
            return 0;
        else
            return -1;
        break;
    case 'r':
        // checking whether vertically backwards there are something in the way
        // or if an opponent figure stands on the target field (< 96  && > 64 means upper case character --> opponent)
        if (x - xx < 0 && y - yy == 0) {
            for (i = x + 1; i < xx; i++) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether vertically upwards there are something in the way
        if (x - xx > 0 && y - yy == 0) {
            for (i = x - 1; i > xx; i--) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally leftwards there are something in the way
        if (x - xx == 0 && y - yy > 0) {
            for (i = y - 1; i > yy; i--) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally rightwards there are something in the way
        if (x - xx == 0 && y - yy < 0) {
            for (i = y + 1; i < yy; i++) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'h':
        if ((abs(x - xx) == 1 && abs(y - yy) == 2 && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' ')) || (abs(x - xx) == 2 && abs(y - yy) == 1 && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' ')))
            return 0;
        else
            return -1;
        break;
    case 'b':
        // BISHOP: it must be checked whether there is some figure in the way or not
        // hitting an opponent at the very end is permitted
        // left - up
        if (x - xx == y - yy && x - xx > 0) {
            for (i = x - 1, j = y - 1; i > xx; i--, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - down
        if (x - xx == y - yy && x - xx < 0) {
            for (i = x + 1, j = y + 1; i < xx; i++, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - up
        if (x - xx == yy - y && y - yy < 0) {
            for (i = x - 1, j = y + 1; i > xx; i--, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // left - down
        if (xx - x == y - yy && x - xx < 0) {
            for (i = x + 1, j = y - 1; i < xx; i++, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'q':
        // ROOK-like behavior:
        // checking whether vertically backwards there are something in the way
        // or if an opponent figure stands on the target field (< 96  && > 64 means upper case character --> opponent)
        if (x - xx < 0 && y - yy == 0) {
            for (i = x + 1; i < xx; i++) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether vertically upwards there are something in the way
        if (x - xx > 0 && y - yy == 0) {
            for (i = x - 1; i > xx; i--) {
                if (chessboard[i][y] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally leftwards there are something in the way
        if (x - xx == 0 && y - yy > 0) {
            for (i = y - 1; i > yy; i--) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // checking whether horizontally rightwards there are something in the way
        if (x - xx == 0 && y - yy < 0) {
            for (i = y + 1; i < yy; i++) {
                if (chessboard[x][i] != ' ')
                    break;
            }
            if (i == yy && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // BISHOP-like behavior:
        // it must be checked whether there is some figure in the way or not
        // hitting an opponent at the very end is permitted
        // left - up
        if (x - xx == y - yy && x - xx > 0) {
            for (i = x - 1, j = y - 1; i > xx; i--, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - down
        if (x - xx == y - yy && x - xx < 0) {
            for (i = x + 1, j = y + 1; i < xx; i++, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // right - up
        if (x - xx == yy - y && y - yy < 0) {
            for (i = x - 1, j = y + 1; i > xx; i--, j++) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        // left - down
        if (xx - x == y - yy && x - xx < 0) {
            for (i = x + 1, j = y - 1; i < xx; i++, j--) {
                if (chessboard[i][j] != ' ')
                    break;
            }
            if (i == xx && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' '))
                return 0;
            else
                return -1;
        }
        break;
    case 'k':
        if (abs(x - xx) == 1 && (abs(y - yy) == 1 || y - yy == 0) && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' ')) //while moving one step vertically or aside
            return 0;
        else if (x - xx == 0 && abs(y - yy) == 1 && ((chessboard[xx][yy] < 96 && chessboard[xx][yy] > 64) || chessboard[xx][yy] == ' ')) // while moving one step to the left or to the right
            return 0;
        else
            return -1;
        break;
    default:
        break;
    }


}

int move_figure(char chessboard[8][8], int x, int y, int xx, int yy)
{
    chessboard[xx][yy] = chessboard[x][y];
    chessboard[x][y] = ' ';
}

void print_board(char chessboard[8][8])
    {
        // upper line with dots
        setBackgroundColor(WHITE);
        setColor(BLACK);
        printf("   ");
        for (int i = 0; i < 8; i++) {
            if (i % 2 == 0) {
                setBackgroundColor(BLACK);
                setColor(WHITE);
            } else {
                setBackgroundColor(WHITE);
                setColor(BLACK);
            }
            printf(" %d ", i);
        }
        printf("\n");
        //printing the actual content of the array, painting the fields respectively..
        for (int i = 0; i < 8; i++) {
            if (i % 2 == 0) {
                setBackgroundColor(BLACK);
                setColor(WHITE);
            } else {
                setBackgroundColor(WHITE);
                setColor(BLACK);
            }
            printf(" %d ", i);
            for (int j = 0; j < 8; j++) {
                if ((i + j) % 2 == 0) {
                    setBackgroundColor(WHITE);
                    setColor(BLACK);
                    printf(" %c ", chessboard[i][j]);
                    resetColor();
                } else {
                    setBackgroundColor(BLACK);
                    setColor(WHITE);
                    printf(" %c ", chessboard[i][j]);
                    resetColor();
                }
            }
            printf("\n");
        }
    }

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

void clear()
    {
        system("cls");
    }

int get_coord(char *text, char input[5], int *x, int *y)
    {
        char *token;
        char *ptr;
        puts(text);
        set_cursor_pos(strlen(text) + 1, get_cursor_y() - 1);
        gets(input);
        token = strtok(input, " ");
        if (token != NULL && is_num(token)) {
            *x = strtol(token, &ptr, 10);
            if (*x > 7)
                return -1;
            token = strtok(NULL, " ");
        } else {
            return -1;
        }
        if (token != NULL && is_num(token)) {
            *y = strtol(token, &ptr, 10);
            if (*y > 7)
                return -1;
        } else {
            return -1;
        }
        return 0;
    }

// gives back '1' if the input can be a number and '0' if it cannot
int is_num(char* str)
    {
        int ret = 0;
        int count = 0;
        for (int i = 0; i < strlen(str); i++) {
            if (47 < str[i] && str[i] < 58)
                count++;
        }

        if (count == strlen(str))
            return 1;
        else
            return 0;
    }


