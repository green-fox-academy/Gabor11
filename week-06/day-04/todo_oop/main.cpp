#include <iostream>
#include <stdlib.h>
#include "include/Task.h"
#include "include/Control.h"
#include <string>
#include <vector>

using namespace std;

void start_screen();
void clear();

/*
 * Main function.
 */
int main()
{
    Control cntrl;
    start_screen();
    while(!cntrl.exit()) {
        cntrl.read_proc();
    }
    return 0;
}

/*
 * Shows the list of commands.
 */
void start_screen()
{
    clear();
    char c = 0;
    cout << "Todo application\n"
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
            "-lp  Lists all the tasks by priority\n" << endl;
    while (c != 10) {
        cin.get(c);
    }
    clear();
}

/*
 * Calls the OS to clear the screen. (works only in windows)
 */
void clear()
{
    system("clear");
}
