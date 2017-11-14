#include <iostream>
#include <string>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main() {

    vector <int> vect;

    vect.push_back(21);
    vect.push_back(3);
    vect.push_back(24);
    vect.push_back(13);
    vect.push_back(22);

    cout << vect[2] << endl;

    return 0;
}
