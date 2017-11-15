#include <iostream>
#include <vector>

using namespace std;

// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins.

class Human {
public:
    virtual void travelling()
    {
        cout << "I am walking." << endl;
    }
};

class SuperHuman: public Human {
public:
    void travelling()
    {
        cout << "I am flying." << endl;
    }
};

class AquaHuman: public Human {
public:
    void travelling()
    {
        cout << "I am riding on dolphins." << endl;
    }
};

int main()
{
    Human man;
    SuperHuman superman;
    AquaHuman fishman;

    man.travelling();
    superman.travelling();
    fishman.travelling();

    return 0;
}
