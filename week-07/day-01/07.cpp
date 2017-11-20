#include <iostream>
#include <stdexcept>

using namespace std;
//Try to run the following code!

int main () {

    try {
        int index = 200;
        int int_array[5] = {1, 2, 3, 4, 5};

        if (index >= sizeof(int_array)/sizeof(int) || index < 0) {
            throw runtime_error("array index out of range");
            throw 0;
            throw 'a';
        }
        cout << int_array[index];
    }
    catch (...){
        cout << "error";
    }

    return 0;
}

//The program should compile but crash!
//Create a solution for this problem using try-catch block!
