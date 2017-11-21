#include <iostream>
#include <iomanip>

using namespace std;

// Now, create 2 functions. They should bear the same name.
// These functions should multiple their parameters.
// The first should return float and take two arguments of the type float.
// The second function should return int and take two arguments of integer type.
// Use these two functions and print out the results.
//
// Compile the code You wrote. Note the output of the compiler. Think about it, google it.
// Now, put one of the functions into comment. (So it's still legible but won't compile.)
// Try compiling it again, and watch what the results are.
//
// Switch the two function declarations. Ucomment the one You commented out and comment out the one
// that ran before. Compile it and compare the results again.
//
// What did You learn from this exercise?
// Write it down in a comment into Your file!
/*
int multiply(int a, int b)
{
    return a * b;
}
*/

float multiply(float a, float b)
{
    return a * b;
}


int main() {

    cout << fixed;
    cout << setprecision(2) << "first result: " << multiply(5, 6) << endl;
    cout << "second result: " << multiply(5.6f, 4.3f) << endl;

	return 0;
}


//switching off the 'float' function results in using the one with 'int' returning value..
// --> digits after the decimal point will not be regarded

//switching off the 'int' returning function makes the other function called in the main()..
// --> the two functioncalling returns with the expected values without problems.
// --> difference can be seen, when we use "setprecision(2)" and float numbers are distiguishable..
