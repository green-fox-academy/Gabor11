#include <iostream>
using namespace std;

// Create a Class named Integer. It should have one int member variable.
// Create add() methods to it. They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.

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


    void add(Integer& first, Integer& second, Integer& third)
    {
        a += first.a;
        a += second.a;
        a += third.a;
    }
};

int main() {

    Integer someinteger;
    Integer someotherinteger(6);
    Integer adifferentint(4);
    Integer anotherone(3);

    someinteger.add(someotherinteger);
    adifferentint.add(anotherone, someinteger);
    adifferentint.add(anotherone, someinteger, someotherinteger);

    cout << adifferentint.get() << endl;

	return 0;
}
