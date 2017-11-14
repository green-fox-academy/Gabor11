#include <iostream>
#include <string>
#define PI 3.1415926535897;

using namespace std;

class Circle {
    private:
        double radius;
    public:
        Circle(double radius)
        {
            this->radius = radius;
        }
        double get_circumference()
        {
            return 2 * radius * PI;
        }

        double get_area()
        {
            return radius * radius * PI;
        }
};

int main() {
    // Create a `Circle` class that takes it's radius as cinstructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area

    Circle crcl(5);

    cout << "This circle has " << crcl.get_circumference() << " circumference and " << crcl.get_area() << " area." << endl;

    return 0;
}
