#include <iostream>
#include <stdexcept>

using namespace std;

// Write a try - catch block.
// Throws a bulit-in exception in the try block
// Catch it in the catch block and write it out.
// Don't forget includes

int main() {

    try {
        throw runtime_error("Some error happened");
    }
    catch(runtime_error &err){
        cout << err.what();

    }
	return 0;
}
