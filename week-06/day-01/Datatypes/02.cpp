#include <iostream>

using namespace std;

// Define several things as a variable then print their values
// Your name as a string
// Your age as an integer
// Your height in meters as a double
// Whether you are married or not as a boolean

int main()
{
    string name = "Gabor";
    int age = 27;
    double height = 1.74;
    bool married = false;

    cout << name << endl << age << endl;

    cout.precision(2);

    cout << fixed << height << endl;

    if (married) {
        cout << "married" << endl;
    } else {
        cout << "not married" << endl;
    }

    return 0;
}
