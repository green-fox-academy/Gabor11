#include <stdio.h>
#include <stdlib.h>

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
int set_up_board(char chessboard[8][8]);
void print_board(char chessboard[8][8]);

int main()
{
    char chessboard[8][8] = {'\0'};
    set_up_board(chessboard);
    print_board(chessboard);


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
        int i = 0;
        if (x - xx < 0 && y - yy == 0) {
            for (i = x; i < xx; i++) {

            }
        }

        break;
    case 'H':
        break;
    case 'B':
        break;
    case 'Q':
        break;
    case 'K':
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
        break;
    case 'h':
        break;
    case 'b':
        break;
    case 'q':
        break;
    case 'k':
        break;
    default:
        break;
    }


}

void print_board(char chessboard[8][8])
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", chessboard[i][j]);
        }
        printf("\n");
    }
}


