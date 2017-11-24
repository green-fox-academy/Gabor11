#ifndef METHODS_H
#define METHODS_H
#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include "../Black Magic/SerialPortWrapper.h"

using namespace std;

struct temp_rec{
    long timestamp;
    int temperature;
};

class Methods
{
    public:
        Methods();
        virtual ~Methods();

        void open_port();
        void start_stop_log();
        void close_port();
        void list_after_errorhandling();
        bool filter_incoming_line(string line);



    protected:

    private:
        SerialPortWrapper *serial;
        vector <string> tokens;
        void tokenize(string input);
        temp_rec string_to_temp_rec(string line);
        vector <temp_rec> temperatures;

};

#endif // METHODS_H
