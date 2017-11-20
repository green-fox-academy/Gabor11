#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an char in the try block
// Catch it in the catch block and write it out.

int main() {

    try {
        throw 'x';
    }
    catch (char e){
        cout << "An exception occurred. Exception char: " << e << endl;
    }


	return 0;
}
