#include <iostream>

using namespace std;

// store your personal data in Variables
// string name, int age, int slice_of_pizza_you_can_eat
// allocate memory dynamically for these variables
// create a sentense using these variables
// free the allocated memory

int main() {
    string *name = new string;
    int *age = new int;
    int *slice_of_pizza_you_can_eat = new int;

    *name = "Gabor";
    *age = 27;
    *slice_of_pizza_you_can_eat = 6;

    cout << "I am " << *name << ", I am " << *age << " years old and I can eat " << *slice_of_pizza_you_can_eat << " slices of pizza" << endl;

    delete name;
    delete age;
    delete slice_of_pizza_you_can_eat;

    return 0;
}
