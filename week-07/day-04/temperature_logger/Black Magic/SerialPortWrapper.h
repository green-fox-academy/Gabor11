#ifndef SERIALPORTWRAPPER_H_
#define SERIALPORTWRAPPER_H_

#include <string>
#include <vector>

using namespace std;

class SerialPortWrapper {
    public:
        static vector<string> listAvailablePorts();

        SerialPortWrapper(string portName, int baudRate);

        void openPort();
        void readLineFromPort(string *line);
        void closePort();
        bool open();

    private:
        string _portName;
        int _baudRate;
        int _portIdx;
        bool _open;
};

#endif // SERIALPORTWRAPPER_H_
