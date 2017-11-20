#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.

int main() {

    try {
        throw 23;
    }
    catch (int e){
        cout << "An exception occurred. Exception Nr. " << e << endl;
    }


	return 0;
}
