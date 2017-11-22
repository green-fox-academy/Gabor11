#include "User.h"

User::User(string name, uint32_t pin_code, uint32_t money)
{
    this->name = name;
    if (pin_precheck(pin_code)) {
        this->pin_code = pin_code;
    } else {
        throw invalid_argument("pincode must be of right length\n4 for customers\n8 for administrators");
        }
    this->money = money;
}

bool User::pin_precheck(uint32_t pin)
{
    int count = 0;
    while (pin > 0) {
        pin /= 10;
        count++;
    }

    if (count == pin_len)
        return true;
    else
        return false;
}

string User::get_name()
{
    return name;
}

int32_t User::get_money()
{
    return money;
}

User::~User()
{
    //dtor
}

Customer::Customer(string name, uint32_t pin_code, uint32_t money) : User(name, pin_code, money)
{
     //This occurs AFTER BaseClass(params) is called first and can
     //perform additional initialization for the derived class
}
