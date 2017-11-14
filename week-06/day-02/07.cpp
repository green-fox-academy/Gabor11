#include <iostream>
#include <string>

using namespace std;

class Pirate {
private:
    int count = 0;
public:
    void drink_rum()
    {
        count++;
    }
    string hows_going_mate()
    {
        if (count > 4) {
            return "Arrrr!";
        } else {
            return "Nothin'";
        }
    }
};

int main() {
    // create a pirate class
    // it should have 2 methods
    // drink_rum()
    // hows_goin_mate()
    // if the drink_rum was called at least 5 times:
    // hows_goin_mate should return "Arrrr!"
    // "Nothin'" otherwise
    Pirate jack;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;
    jack.drink_rum();
    cout << "How's goin Jack? " << endl << jack.hows_going_mate() << endl;



    return 0;
}
