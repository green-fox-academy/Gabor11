#include <stdio.h>
#include <stdlib.h>
#include "storage.h"
#include "logic.h"

int main()
{
    char input[256];
    char errortext[256];
    task task_list[10] = {'\0'};
    int next_ID = 0;
    char c = 0;
    defining_commands();

    start_screen();
    while (c != 27) {
        gets(input);

        process(task_list, input, &next_ID, errortext);
    }

    printf("Take care! Good bye!\n");
    return 0;
}

void start_screen()
{
    clear();
    char c = 0;
    printf( "Todo application\n"
            "====================\n"
            "Commands:\n"
            "-a   Adds a new task\n"
            "-wr  Write current todos to file\n"
            "-rd  Read todos from a file\n"
            "-l   Lists all the tasks\n"
            "-e   Empty the list\n"
            "-rm   Removes a task\n"
            "-c   Completes a task\n"
            "-p   Add priority to a task\n"
            "-lp  Lists all the tasks by priority\n");
    while (c != 13) {
        c = getch();
    }
    clear();
}

void clear()
{
    system("cls");
}
