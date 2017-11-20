#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Create a function that prints out the fist "N" positive odd numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   1, 3, 5, 7, 9
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */

void print_first_n_positive_odd_numbers(int n)
{
    if (n <= 0)
        throw runtime_error("Invalid parameter");
    for (int i = 1; i <= 2 * (n - 1); i += 2)
        cout << i << ", ";
    cout << 2 * n - 1;
}

int main() {
    try {
        print_first_n_positive_odd_numbers(0);
    }
    catch (runtime_error &err) {
        cout << err.what();
    }

    return 0;
}
