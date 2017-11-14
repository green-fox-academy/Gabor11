#include <iostream>

// Create your own namespace, called Person
// store your name as a string
// your age as an integer
// and your favorite number as an integer
// write them out in main()

using namespace std;

namespace Person{
    string name = "Gabor";
    int age = 27;
    int fav_num = 11;
}

using namespace Person;

int main()
{
    cout << name << endl << age << endl << fav_num << endl;
    return 0;
}
