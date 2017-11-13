#include <iostream>

using namespace std;

// Greet 3 of your classmates with this program, in three separate lines
// like:
//
// Hello, Esther!
// Hello, Mary!
// Hello, Joe!
// Store their names in separate string type variables


int main()
{
    string friends[] = { "Oscar", "Agi", "Armin" };

    for (int i = 0; i < 3; i++) {
        cout << "Hello " << friends[i] << endl;
    }

    return 0;
}
