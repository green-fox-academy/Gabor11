#ifndef CONTROL_H
#define CONTROL_H
#include <vector>
#include <string>
#include "../User.h"
#include "Datahandle.h"

class Control
{
    public:
        Control();
        virtual ~Control();
        int proc();
        bool exit();

    protected:

    private:
        int count; // counts the added tasks
        bool _exit;
        bool valid_registration;
        Datahandle handler;
};

#endif // CONTROL_H
