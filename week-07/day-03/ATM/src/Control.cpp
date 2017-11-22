#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include "Control.h"

using namespace std;

Control::Control()
{

    count = 0; // setting initial value of actual number of tasks

    //ctor
    valid_registration = false;
    _exit = false;
}



int Control::proc()
{

    char switcher = 0;
    switcher = getchar();

switch (switcher) {
    case 'w':
        //handler.withdraw();
        break;
    case 'r':
        while(!valid_registration) {
            try {
                valid_registration = handler.register_as_customer();
            }
            catch (invalid_argument &err){
                cout << "parameter error: " << err.what();
                continue;
            }
        }
        break;
/*    case 'l':
        //handler.log_in_as_admin();
        break;
    case '?':
        //handler.who_is_richest();
        break;
*/
     case 'e':
        _exit = true;
        break;
    default:
        cout << "wrong input" << endl;
        break;
    }

    valid_registration = false;
}

bool Control::exit()
{
    return _exit;
}

Control::~Control()
{
    //dtor
}
