#include <iostream>
using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.
string concatenate (string one, string two)
{
    return one + two;
}

string concatenate (string one, string two, string three)
{
    return one + two + three;
}

string concatenate (string one, string two, string three, string four)
{
    return one + two + three + four;
}

int main() {

    cout << concatenate("I", " am") << endl;
    cout << concatenate("the ", "master ", "of") << endl;
    cout << concatenate("four", " string", " concatenation", " today") << endl;
	return 0;
}
