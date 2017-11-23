#ifndef METHODS_H
#define METHODS_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "../Black Magic/SerialPortWrapper.h"

using namespace std;

class Methods
{
    public:
        Methods();
        virtual ~Methods();
        void command_screen(); // shows the commands
        void clear(); // erases all content from the screen
        void open_port();
        void start_stop_log();
        void close_port();
        void list_after_errorhandling();
        bool filter_incoming_line(string line);
        void pause();

    protected:

    private:
        SerialPortWrapper *serial;
        vector <string> tokens;
        void tokenize(string input);

};

#endif // METHODS_H
