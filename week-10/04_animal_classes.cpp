#include <iostream>
#include <string>

using namespace std;

class Animal {
private:
protected:
    uint8_t hunger;
    uint8_t thirst;
public:
    Animal()
    {
        cout << "Hello, I am a new animal." << endl;
        this->hunger = 50;
        this->thirst = 50;
    }

    ~Animal()
    {
        cout << "arrgghh" << endl;
    }

    /*************** GETTERS ****************/

    uint8_t get_hunger()
    {
        return hunger;
    }

    uint8_t get_thirst()
    {
        return thirst;
    }

    void eat()
    {
        if (hunger > 0)
            hunger--;
    }

    void drink()
    {
        if (thirst > 0)
            thirst--;
    }

    void play()
    {
        if (thirst < 255 && hunger < 255) {
            hunger++;
            thirst++;
        } else {
            cout << "I am dying.. " << endl;
        }
    }

};

int main() {
//Create Animal class
//Every animal has a hunger value, which is a whole number
//Every animal has a thirst value, which is a whole number
//when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//Every animal can drink() which decreases their thirst by one
//Every animal can play() which increases both by one

    Animal animal;
    cout << "hunger: " << (int)animal.get_hunger() << "thirst: " << (int)animal.get_thirst() << endl;
    animal.play();
    animal.play();
    animal.play();
    cout << "hunger: " << (int)animal.get_hunger() << "thirst: " << (int)animal.get_thirst() << endl;

  return 0;
}


