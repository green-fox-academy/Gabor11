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

    count = 0; // setting initial value of actual number of tasks

    //ctor
}

string Control::get_input()
{
    string input;
    getline(cin, input);
    return input;
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

switch (switcher) {
    case 0:
        handler.add_to_list(count++, operand);
        break;
    case 1:
        // write to file
        break;
    case 2:
        // read from file
        break;
    case 3:
        // print list to screen
        handler.print_list();
        break;
    case 4:
        // empty list
        break;
    case 5:
        // remove task from list
        break;
    case 6:
        // edit progress of a task
        break;
    case 7:
        // edit priority of a task
        break;
    case 8:
        // print list ordered by priority
        break;
    default:
        cout << "default\n" << endl;

        break;
    }
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
