#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include "Task.h"
#include "Datahandle.h"

class Control
{
    public:
        Control();
        virtual ~Control();
        string get_input();
        int proc(string input);

    protected:

    private:
        int count; // counts the added tasks
        void tokenize(string input);
        vector <string> tokens;
        vector <string> commands;
        string errortext;
        Datahandle handler;
};

#endif // CONTROL_H
