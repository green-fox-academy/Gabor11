#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL)); // This initializes the random generator.
	int rnd = 0;
	for (int i=0; i<20; i++) {
		rnd = rand() % 5; // generate a random number in the range [0, 4]
		try {
			switch (rnd) {
				case 0:
					throw 3.2f;
					break;
				case 1:
					throw double(43.56);
					break;
				case 3:
					throw "Abrakadabra";
					break;
				case 4:
					throw false;
					break;
				default:
					throw 12;
					break;
			}
		}
// Write catch blocks for each possibly thrown exception.
// In each catch block write out what the exception's type was. And what the exceptions value was.
        catch (double a) {
            cout << "Double type exception was thrown: " << a << endl;
        }
        catch (int b) {
            cout << "Integer type exception was thrown: " << b << endl;
        }
        catch (float c) {
            cout << "Float type exception was thrown: " << c << endl;
        }
        catch (bool d) {
            cout << "Boolean type exception was thrown: " << d << endl;
        }
        catch (char const *e) {
            cout << "String type exception was thrown: " << e << endl;
        }
	}

	return 0;
}
