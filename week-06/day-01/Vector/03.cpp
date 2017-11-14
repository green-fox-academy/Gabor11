#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//create a vector of integers with the size of 20
	//fill this vector with random numbers from 0 to 10
	//print the items of the vector
  //remove the even numbers, then print the items again

  vector <int> int_vect(20);

    int size = int_vect.size();
    for (int i = 0; i < size; ++i) {
        int_vect.insert(int_vect.begin() + i, rand() % 10);
        cout << int_vect[i] << endl;
    }

    cout << "--------" << endl;

    for (int i = 0; i < int_vect.size(); ++i) {
        if (int_vect[i] % 2) {
            cout << int_vect[i] << endl;
        } else {
            int_vect.erase(int_vect.begin() + i);
            i--;
        }
    }

  return 0;
}
