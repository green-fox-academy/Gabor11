#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise and add two methods:
// One which takes an Integer& parameter and adds the value of it to the member variable of this.
// One which takes an int and adds the value of it to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively.

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


int main() {
    Integer int1(3);
    Integer int2(4);

    int1.add(int2);
    cout << int1.get() << endl;

    int1.add(3);
    cout << int1.get() << endl;

	return 0;
}
