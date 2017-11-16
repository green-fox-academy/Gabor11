#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Control.h"
#define MAX_COMMAND_LENGTH 4

using namespace std;

Control::Control()
{
    //initializing commands vector
    commands.push_back("-a");
    commands.push_back("-wr");
    commands.push_back("-rd");
    commands.push_back("-l");
    commands.push_back("-e");
    commands.push_back("-rm");
    commands.push_back("-c");
    commands.push_back("-p");
    commands.push_back("-lp");



    //ctor
}

int Control::proc(string input)
{
    int switcher = -1;
    int i;
    string command;
    string operand;

    tokenize(input);
    command = tokens[0];
    input.erase(0, 3);
    operand = input;

    for (i = 0; i < commands.size(); i++) {
        if (commands[i] == command) {
            switcher = i;
            break;
        }
    }

    if (switcher == 0) {
       // Task *tsk = new Task(1, operand);
       Task tsk = Task(1, operand);
        task_list.push_back(tsk);
        cout << "new task added" << endl;
        return 0;
    }

    return 1;
   /* switch (switcher) {
    case 0:
        if (add_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        else
            puts("new task added\n");
        break;
    case 1:
        if (write_to_file(task_list, next_ID, errortext, filename) != 0)
            puts(errortext);
        else
            puts("tasks have been written to \"tasks.csv\"");
        break;
    case 2:
        if (read_from_file(task_list, next_ID, errortext, filename) != 0)
            puts(errortext);
        else
            puts("tasks have been written to \"tasks.csv\"");
        break;
    case 3:
        if(list(task_list, next_ID, errortext) != 0)
            puts(errortext);
        break;
    case 4:
        if(empty_list(task_list, next_ID, errortext) != 0)
            puts(errortext);
        break;
    case 5:
        if(remove_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 6:
        if(progress_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 7:
        if(prior_task(task_list, next_ID, operand, errortext) != 0)
            puts(errortext);
        break;
    case 8:
        //
        break;
    default:
        printf("default\n");

        break;
    }
    */
}

void Control::tokenize(string input)
{
/*
    string tempstr;
    tempstr = input;
    tempstr = strtok(tempstr, " ");
    if (strlen(tempstr) >= MAX_COMMAND_LENGTH) {
        errortext = "invalid length of operator";
        tempstr = "err";
    }
    return tempstr;
*/
    string str = input;
    string buf; // Have a buffer string
    stringstream ss(str); // Insert the string into a stream

    while (ss >> buf)
        tokens.push_back(buf);

}

Control::~Control()
{
    //dtor
}
