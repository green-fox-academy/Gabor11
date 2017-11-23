#include "Control.h"

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
    switcher = getchar();

    switch (switcher) {
        case 'h':
            meths.command_screen();
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

bool Control::exit()
{
    return _exit;
}

