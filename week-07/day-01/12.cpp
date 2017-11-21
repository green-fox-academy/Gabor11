
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

string int_checker(int input)
{
    if (input > 5) {
        throw input - 5;
    } else if (input < 0) {
        throw "It is a negative number";

    return sentence[input];
    }
}
int main()
{
    try  {
        int_checker(-2);
    }
    catch (const char* e){
        cout <<  e <<  endl;

    }
    catch (int e){
        cout << "It is " << e << " times larger than 5" << endl;
    }
    try  {
        int_checker(6);
    }
    catch (const char* e){
        cout <<  e <<  endl;

    }
    catch (int e){
        cout << "It is " << e << " times larger than 5" << endl;
    }
    return 0;
}
