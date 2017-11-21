#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and create two operators for it:
// a + operator that takes and Integer& and adds it's member variables value to this.
// a + operator that takes an int and adds it's value to the member variable of this.
//
// Consider what the return value of the operator should be: Integer& or void? Or something else?
// Make it so that the code below compiles and works.

class Integer {
private:
    int a;
public:
    Integer()
    {
        a = 0;
    }

    Integer(int a)
    {
        this->a = a;
    }

    Integer(Integer& _other): a(_other.a)
    {
    }
    int get()
    {
        return a;
    }
    void add(Integer& first)
    {
        a += first.a;
    }

    void add(int a)
    {
        this->a += a;
    }


};

Integer& operator + (Integer& _int1, Integer& _int2) {
    Integer ret(_int1.get() + _int2.get());
    return ret;
}

Integer& operator + (Integer& _int1, int _int2) {
    Integer ret(_int1.get() + _int2);
    return ret;
}

int main () {
    Integer a(12);
    Integer b(12);

    cout << (a + b).get() << endl;
    cout << (a + 12).get() << endl;
    cout << (a + b + 12).get() << endl;

    return 0;
}
