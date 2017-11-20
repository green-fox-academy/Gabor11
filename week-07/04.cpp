#include <iostream>
using namespace std;

// Create a function which throws an integer
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void throw_integer()
{
    throw 11;
}

int main() {

    try {
        throw_integer();
    }

    catch (int e) {
        cout << "function threw an integer: " << e << endl;
    }

	return 0;
}
