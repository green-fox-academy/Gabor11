#include <iostream>
#include "Task.h"
#include "Control.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    Control cntrl;

    cntrl.proc(cntrl.get_input());
    cntrl.proc(cntrl.get_input());


    return 0;
}
