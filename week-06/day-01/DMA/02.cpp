#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main() {

    int count = 0;

    cout << "Please enter how many numbers you will enter: ";
    cin >> count;

    int *numbers = new int[count];

    for (int i = 0; i < count; ++i) {
        cout << "No" << i + 1 << endl;
        cin >> *(numbers + i);
    }

    double average = 0;

    for (int i = 0; i < count; ++i) {
        average += *(numbers +i);
    }

    average /= (double)count;

    cout << "The average of these numbers: " << average;

    delete numbers;

  return 0;
}
