#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string type;
    double km;
public:
    Car(string type, int km)
    {
        this->type = type;
        this->km = km;
    }
    void run(double km)
    {
        this->km += km;
    }

    double get_km()
    {
        return km;
    }

    string get_type()
    {
        return type;
    }
};

int main() {
    // Create a class called "Car"
    // It should have a "type" property that stores the car's type in a string eg: "Mazda"
    // It should have a "km" property that stores how many kilometers it have run
    // The km and the type property should be a parmeter in the constructor
    // It should have a method called "run" that takes a number and increments the "km" property by it

    Car car("Mazda", 100000);
    cout << "This is a " << car.get_type() << " which has run " << car.get_km() << " already." << endl;

    return 0;
}
