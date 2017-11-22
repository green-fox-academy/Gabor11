#include <iostream>
#include <stdlib.h>
#include <string>
#include "User.h"
#include "Control.h"

using namespace std;

void start_screen();
void clear();

int main()
{
    Control cntrl;
    start_screen();
    while(!cntrl.exit()) {
        cntrl.proc();
    }

    return 0;
}

void start_screen()
{
    clear();
    char c = 0;
    cout << "ATM application\n"
            "====================\n"
            "Command Keys:\n"
            "'w'   Withdraw money\n"
            "'r'   Register as a new customer\n"
            "'l'   Log in as administrator\n"
            "'?'   Who is richest?\n"
            "'e'   Exit\n"
            "Program starts after ENTER\n"
            "====================" << endl;

    while (c != 10) {
        cin.get(c);
    }
    clear();
}

void clear()
{
    system("clear");
}
