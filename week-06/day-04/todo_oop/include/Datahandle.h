#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <vector>
#include <iostream>
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
protected:
private:
    vector <Task> task_list;
    string filename;
};

#endif // DATAHANDLE_H
