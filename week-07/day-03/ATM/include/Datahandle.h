#ifndef DATAHANDLE_H
#define DATAHANDLE_H
#include <vector>
#include <iostream>
#include <fstream>
#include "../User.h"

using namespace std;

class Datahandle
{
public:
    Datahandle();
    virtual ~Datahandle();
    bool register_as_customer();
    int print_list();
    int add_to_list(string name, uint32_t pin_code, uint32_t money);
    int write_to_file();
    int read_from_file();
    int empty_list();

protected:
private:
    vector <User> users;
    string filename;
    bool check_username(string username);
};

#endif // DATAHANDLE_H
