#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//create an integer vector with the size of 5 and print all elements of it
	vector <int> int_vector;

    int_vector.push_back(21);
    int_vector.push_back(3);
    int_vector.push_back(24);
    int_vector.push_back(13);
    int_vector.push_back(22);

    for (int i = 0; i < int_vector.size(); ++i) {
        cout << int_vector[i] << endl;
    }

  return 0;
}
