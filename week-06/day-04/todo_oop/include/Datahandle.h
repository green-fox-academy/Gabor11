#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <vector>
#include <iostream>
#include <fstream>
#include "Task.h"

using namespace std;

class Datahandle
{
public:
    Datahandle();
    virtual ~Datahandle();
    int print_list();
    int add_to_list(int num, int progress, string text, int prio);
    int add_to_list(int num, string text);
    int write_to_file();
    int read_from_file();
    int empty_list();
    int remove_task();
    int set_progress();
    int add_priority();
    int list_by_priority();
protected:
private:
    vector <Task> task_list;
    string filename;
};

#endif // DATAHANDLE_H
