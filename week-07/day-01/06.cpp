#include <iostream>
#include <stdexcept>

using namespace std;

// Create a function which throws a built-in exception
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws
void throw_exception()
{
    throw runtime_error("Some error happened");;
}

int main() {

    try {
        throw_exception();
    }

    catch (runtime_error &err){
        cout << "Function threw following error: " << err.what() << endl;
    }

	return 0;
}
