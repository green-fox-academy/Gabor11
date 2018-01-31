#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "../include/Control.h"
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
    commands.push_back("-exit");

    count = 0; // setting initial value of actual number of tasks

    //ctor

    _exit = false;
}



int Control::read_proc()
{

    string input;
    getline(cin, input);

    int switcher = -1;
    int i;
    string command;
    string operand;

    tokenize(input);
    command = tokens[0];
    input.erase(0, tokens[0].size());
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
        handler.write_to_file();
        break;
    case 2:
        // read from file
        handler.read_from_file();
        break;
    case 3:
        // print list to screen
        handler.print_list();
        break;
    case 4:
        // empty list
        handler.empty_list();
        break;
    case 5:
        // remove task from list
        //handler.remove_task();
        break;
    case 6:
        // edit progress of a task
        //handler.set_progress();
        break;
    case 7:
        // edit priority of a task
        //handler.add_priority();
        break;
    case 8:
        // print list ordered by priority
        break;
    case 9:
        _exit = true;// print list ordered by priority
        break;
    default:
        cout << "wrong input" << endl;

        break;
    }
    tokens.clear();
}

void Control::tokenize(string input)
{
    string str = input;
    stringstream ss(str); // Insert the string into a stream
    ss >> buf;
    do {
        tokens.push_back(buf);
    }while (ss >> buf);

}

bool Control::exit()
{
    return _exit;
}

Control::~Control()
{
    //dtor
}
