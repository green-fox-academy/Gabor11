#include <iostream>

using namespace std;

// Write a program that prints a few details to the terminal window about you
// It should print each detail to a new line.
//  - Your name
//  - Your age
//  - Do you like coffee? (as a boolen variable)
//
//  Example output:
//  John Doe
//  31
//  Likes coffee: true

int main()
{
    bool coffee_like = true;

    cout << "Gabor Matejka" << endl;
    cout << 27 << endl;
    cout << "Likes coffee: ";

    if (coffee_like) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
