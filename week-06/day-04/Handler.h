#ifndef HANDLER_H
#define HANDLER_H
#include <vector>
#include <string>
#include "Task.h"

class Handler
{
    public:
        Handler();
        virtual ~Handler();
        int process(string input);
        vector <Task> task_list;

    protected:

    private:
        void tokenize(string input);
        vector <string> tokens;
        vector <string> commands;
        string errortext;
        string filename;
};

#endif // HANDLER_H
