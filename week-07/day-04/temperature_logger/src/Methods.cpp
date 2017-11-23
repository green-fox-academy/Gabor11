#include "Methods.h"
#include <cstdio>

Methods::Methods()
{
    //serial = new SerialPortWrapper("COM3", 115200);
    //ctor
}

Methods::~Methods()
{
    //dtor
}

void Methods::command_screen()
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

void Methods::clear()
{
    system("cls");
}

void Methods::pause()
{
    system("pause");
}
void Methods::open_port()
{
    //serial->openPort();
    cout << "opening port" << endl;
}

void Methods::start_stop_log()
{
    cout << "start or stop log" << endl;
}

void Methods::close_port()
{
    //serial->closePort();
    cout << "closing port" << endl;
}

void Methods::list_after_errorhandling()
{       /*
        string line;
        while(1){
            serial->readLineFromPort(&line);
            if (line.length() > 0){
                cout << line << endl;
            }
        }
        */
        cout << "list after errorhandling" << endl;
}

bool Methods::filter_incoming_line(string line)
{
    if (line.length() > 0) {
        tokenize(line);
    } else {
        return false;
    }
    char *endptr;
    int year = strtol(tokens[0].c_str(), &endptr, 10);
    int month = strtol(tokens[1].c_str(), &endptr, 10);
    int day = strtol(tokens[2].c_str(), &endptr, 10);
    int hour = strtol(tokens[3].c_str(), &endptr, 10);
    int minute = strtol(tokens[4].c_str(), &endptr, 10);
    int second = strtol(tokens[5].c_str(), &endptr, 10);
    int temperature = strtol(tokens[6].c_str(), &endptr, 10);


    tokens.clear();
    return true;
}

void Methods::tokenize(string input)
{
    char str[100];
        strcpy(str, input.c_str());
    char *buf;             // have a buffer char array
    string bf;             // have a buffer string
    buf = strtok(str, ". :");
    // in this loop we fill up the vector called 'tokens'
    // by interesting parts of the input
    while (buf != NULL)
    {
        bf = buf;             // making c++ string out of the char array buffer
        tokens.push_back(bf); // 'tokens' is a vector in 'Methods'
        buf = strtok (NULL, ". :");
    }
}
