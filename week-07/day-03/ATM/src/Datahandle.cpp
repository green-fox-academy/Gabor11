#include "Datahandle.h"
#include <vector>



Datahandle::Datahandle()
{
    filename = "ATM_log.txt";
        //ctor
}

bool Datahandle::register_as_customer()
{
    string username;
    int32_t pin_code;
    int32_t money;
    cout << "Enter your user name: ";
    getline(cin, username);
    return check_username(username);


}

bool Datahandle::check_username(string username)
{
    int i = 0;
    if (username.size() > 10)
        throw invalid_argument ("username must be less than 10 characters");
    for (i = 0; i < users.size(); i++) {
        if (users[i].get_name() == username)
            break;
    }
    if (i == users.size())
        return true;
    throw invalid_argument ("username already taken");
    return false;
}

int Datahandle::add_to_list(string name, uint32_t pin_code, uint32_t money)
{
    User user(name, pin_code, money);
    users.push_back(user);
    return 0;
}

int Datahandle::print_list()
{
    for (int i = 0; i < users.size(); i++) {
        cout << users[i].get_name()<< "\t[" << users[i].get_money() << "]" << endl;
    }
    return 0;
}

int Datahandle::write_to_file()
{
    ofstream out_file;
    out_file.open(filename.c_str(), ios::out | ios::trunc);
    for (int i = 0; i < users.size(); i++) {
        out_file << users[i].get_name() << "\t" << users[i].get_money() << endl;
    }
    out_file.close();
    return 0;

}

int Datahandle::empty_list()
{
    users.clear();
    return 0;
}


Datahandle::~Datahandle()
{
    //dtor
}
