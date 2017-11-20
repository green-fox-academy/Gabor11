#include <iostream>
using namespace std;

// Create a function which throws an char
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void throw_char()
{
    throw 'g';
}

int main() {

    try {
        throw_char();
    }

    catch (char e) {
        cout << "function threw a char: " << e << endl;
    }

	return 0;
}
