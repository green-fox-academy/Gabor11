#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private field)

class Shape {
protected:
    double area;
public:
    virtual double calc_area() = 0;
};

class Circle: public Shape {
private:
    double radius;
public:
    Circle(double radius)
    {
        this->radius = radius;
    }
    double calc_area()
    {
        area = radius * radius * 3.14159;
        return area;
    }
};

class Triangle: public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double calc_area()
    {
        double p = (a + b + c)/2;
        area = sqrt(p * (p - a) * (p - b) * (p - c));
        return area;
    }
};

int main()
{
    Circle circle(13);
    Triangle triangle(3, 4, 5);

    cout << "This circle's area: " << circle.calc_area() << endl << "This triangle's area: " << triangle.calc_area() << endl;


    return 0;
}
