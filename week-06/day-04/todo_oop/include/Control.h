#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include "Task.h"

class Control
{
    public:
        Control();
        virtual ~Control();
        int proc(string input);
        vector <Task> task_list;

    protected:

    private:
        void tokenize(string input);
        vector <string> tokens;
        vector <string> commands;
        string errortext;
        string filename;
};

#endif // CONTROL_H
