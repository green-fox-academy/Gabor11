// Countinue the Shape exercise!
// Create getter methods for each values
// (for example: in a Triangle class you should be able to
// get: Height, Base and Area)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
protected:
    double area = 0;
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

    double get_radius()
    {
        return radius;
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
    double get_a()
    {
        return a;
    }
    double get_b()
    {
        return b;
    }
    double get_c()
    {
        return c;
    }
    double get_height_a()
    {
        if (area != 0) {
            return area * 2 / a;
        } else {
            return calc_area() * 2 / a;
        }
    }
    double get_height_b()
    {
        if (area != 0) {
            return area * 2 / b;
        } else {
            return calc_area() * 2 / b;
        }
    }
    double get_height_c()
    {
        if (area != 0) {
            return area * 2 / c;
        } else {
            return calc_area() * 2 / c;
        }
    }

};

int main()
{
    Circle circle(13);
    Triangle triangle(3, 4, 5);

    cout << "This circle's area: " << circle.calc_area() << endl << "This triangle's area: " << triangle.calc_area() << endl;
    cout << "The height on the triangles 'a' side is: " << triangle.get_height_a() << endl;
    return 0;
}
