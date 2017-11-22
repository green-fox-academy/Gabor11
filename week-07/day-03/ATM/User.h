#ifndef USER_H
#define USER_H

#include <stdint.h>
#include <string>
#include <stdexcept>

using namespace std;

class User
{
    public:
        User();
        User(string name, uint32_t pin_code, uint32_t money);
        virtual ~User();
        string get_name();
        int32_t get_money();
    protected:
        string name;
        int32_t pin_code;
        int32_t money;
        bool pin_precheck(uint32_t pin);
        int8_t pin_len = 4;
    private:
};

class Customer: public User {
public:
    Customer(string name, uint32_t pin_code, uint32_t money);
};

#endif // USER_H
