#include "Control.h"
#include <conio.h>

Control::Control()
{
    //ctor
    _exit = false;
}

Control::~Control()
{
    //dtor
}

int Control::proc()
{
    char switcher = 0;
    switcher = getch();

    switch (switcher) {
        case 'h':
            command_screen();
            break;
        case 'o':
            meths.open_port();
            break;
        case 's':
            meths.start_stop_log();
            break;
        case 'c':
            meths.close_port();
            break;
        case 'l':
            meths.list_after_errorhandling();
            break;
        case 'e':
            _exit = true;
            break;
        default:
            throw invalid_argument ("wrong command");
            break;
        return 0;
    }

}

void Control::command_screen()
{
    clear();
    cout << "Temperature Logger Application" << endl;
    cout << "==============================" << endl;
    cout << "Commands:" << endl;
    cout << "h\tShow command list" << endl;
    cout << "o\tOpen port" << endl;
    cout << "s\tStart logging / Stop logging" << endl;
    cout << "c\tClose port" << endl;
    cout << "l\tList after error handling" << endl;
    cout << "e\tExit from the program" << endl;
    pause();
    clear();
}

void Control::clear()
{
    system("cls");
}

void Control::pause()
{
    system("pause");
}

bool Control::exit()
{
    return _exit;
}

