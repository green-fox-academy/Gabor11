#ifndef CONTROL_H
#define CONTROL_H
#include <stdexcept>
#include <string>
#include <vector>
#include "Methods.h"


class Control
{
    public:
        Control();
        virtual ~Control();
        int proc();
        bool exit();
        void pause();
        void command_screen(); // shows the commands
        void clear(); // erases all content from the screen

    protected:

    private:
        bool _exit;
        Methods meths;
};

#endif // CONTROL_H
