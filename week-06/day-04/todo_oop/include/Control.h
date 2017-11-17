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
        int read_proc();
        bool exit();

    protected:

    private:
        int count; // counts the added tasks
        string buf; // outer buffer for processing inputs (in void tokenize(string input))
        bool _exit;
        void tokenize(string input);
        vector <string> tokens;
        vector <string> commands;
        string errortext;
        Datahandle handler;
};

#endif // CONTROL_H
