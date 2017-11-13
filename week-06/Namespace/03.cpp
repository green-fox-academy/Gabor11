#include <iostream>

// Use your costume namespace from the last exercise
// Create a function, which takes the age as a parameter
// and returns the year when you were born

using namespace std;

namespace Person{
    string name = "Gabor";
    int age = 27;
    int fav_num = 11;
}

using namespace Person;

int year_of_birth(int age);

int main()
{
    cout << year_of_birth(age) << endl;

    return 0;
}

int year_of_birth(int age)
{
    return 2017 - age;
}
