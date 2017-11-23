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

    protected:

    private:
        bool _exit;
        Methods meths;
};

#endif // CONTROL_H
