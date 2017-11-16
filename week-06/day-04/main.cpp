#include <iostream>
#include "Task.h"
#include "Handler.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    Handler hndlr;
   // task_list.push_back(Task task(1, "Something to do"));
    /*
    task.set_prio(3);

    cout << "Hello world!" << endl << task.get_text() << " - has the priority of: " << task.get_prio() << endl;
    */
    getline(cin, input);
    hndlr.process(input);
    cout << hndlr.task_list[0].get_text() << endl;
   // cout << task_list[1].get_text() << endl;
    getline(cin, input);
    hndlr.process(input);
    cout << hndlr.task_list[1].get_text() << endl;

    return 0;
}
