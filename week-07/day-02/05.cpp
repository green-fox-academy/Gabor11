#include <iostream>
using namespace std;

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member varibale to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)


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

    void add(Integer& first, Integer& second)
    {
        a += first.a;
        a += second.a;
    }
};


int main() {
    Integer int1(3);
    Integer int2(4);
    Integer int3(int1);
    Integer int4(int2);

    cout << "int1: " << int1.get() << endl;
    cout << "int2: " << int2.get() << endl;
    cout << "int3: " << int3.get() << endl;
    cout << "int4: " << int4.get() << endl;

	return 0;
}
