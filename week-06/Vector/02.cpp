#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	//Create a vector of integers
	//reserve place for 10 element, then fill those place with random numbers between 0 and 10

    vector <int> int_vect(10);

    int size = int_vect.size();
    for (int i = 0; i < size; ++i) {
        int_vect.insert(int_vect.begin() + i, rand() % 10);
        cout << int_vect[i] << endl;
    }

    return 0;
}
