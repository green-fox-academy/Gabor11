#include <iostream>
#include <string>
using namespace std;

// Create a class called ParentClass. It should have two public functions. Both return a string. One virtual, the other not.
// Each should return a unique string.
// Create a ChildClass which inherits from the ParentClass publicly.
// This should override both functions. The virtual and the nonvirtual one both.
// These should return unique string again.
//
// Create a main() function. In this function, create a ParentClass* pointer and instanciate a ChildClass member for that pointer.
// Hint: This should look something like this: ParentClass* a = new ChildClass();
// Print out the result of both functions on this a ponter.
// Print out the result of both functions if You first cast pointer a to be interpreted as of type ChildClass*

class ParentClass {
public:
    virtual string function1() = 0;
    string function2()
    {
        return "some string from original function2";
    }
};

class ChildClass: public ParentClass {
public:
    string function1()
    {
        return "some string from ChildClass.function1";
    }
    string function2()
    {
        return "some string from ChildClass.function2";
    }
};

string printer_parent(ParentClass *parent, int switcher)
{
    if(switcher == 1)
        cout << "function is virtual" << endl;
    else if (switcher == 2)
        cout << parent->function2() << endl;
    else
        cout << "no function like that" << endl;
}

string printer_child(ChildClass *child, int switcher)
{
    if(switcher == 1)
        cout << child->function1() << endl;
    else if (switcher == 2)
        cout << child->function2() << endl;
    else
        cout << "no function like that" << endl;
}

int main()
{

    ParentClass* a = new ChildClass();
    cout << a->function1() << endl;
    cout << a->function2() << endl;
    cout << ((ChildClass*)a)->function1() << endl;
    cout << ((ChildClass*)a)->function2() << endl;

    return 0;
}
