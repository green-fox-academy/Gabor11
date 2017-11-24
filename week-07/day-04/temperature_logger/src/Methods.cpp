#include "Methods.h"
#include <cstdio>
#include <sstream>
#include <iomanip>

Methods::Methods()
{
    serial = new SerialPortWrapper("COM3", 115200);
    //ctor
}

Methods::~Methods()
{
    //dtor
}

temp_rec Methods::string_to_temp_rec(string line) {

	int temperature;
	istringstream exampleStream(line);
	tm parsedDateTime;
	exampleStream >> get_time(&parsedDateTime, "%Y.%m.%d %H:%M:%S")
			>> temperature;
	if (exampleStream.fail()) {
		throw "Invalid string format!";
	}


	if (-273 > temperature || 1000 < temperature) {
		throw "Temperature is out of range!";
	}

	long timestamp = mktime(&parsedDateTime);

	temp_rec rec;
	rec.temperature = temperature;
	rec.timestamp = timestamp;
	return rec;
}
;

void Methods::open_port()
{
    if (!serial->open()) {
        serial->openPort();
        cout << "opening port" << endl;
    } else {
        cout << "already open" << endl;
    }
}

void Methods::start_stop_log()
{
    if (serial->open()) {
        cout << "start or stop log" << endl;
    } else {
        cout << "communication is not open" << endl;
    }
}

void Methods::close_port()
{
    if (serial->open()) {
        serial->closePort();
        cout << "closing port" << endl;
    } else {
        cout << "already closed" << endl;
    }
}

void Methods::list_after_errorhandling()
{
    cout << "list after errorhandling" << endl;
    int temp_vect_length = temperatures.size();
    string line;
    while(serial->open()){
        serial->readLineFromPort(&line);
        try {
            temperatures.push_back(string_to_temp_rec(line));
        }
        catch (...) {
            // ignore failed readings
        }
        if (temperatures.size() != temp_vect_length) {
            /*temp_rec member = temperatures[temp_vect_length];
            long tstamp = member.timestamp;
            int temp = member.tempe */
            cout << temperatures[temp_vect_length].timestamp << " " << temperatures[temp_vect_length].temperature << endl;
        }

    }
    cout << "communication closed" << endl;

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
