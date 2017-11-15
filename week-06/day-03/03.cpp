// Still the shape exercise!
// Create public method called how_much_to_paint()
// which should get the area and the price of the paint as parameters
// It shoud return the costs of the paingting

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape {
protected:
    double area = 0;
public:
    virtual double calc_area() = 0;
    double how_much_to_paint(double price_of_paint)
    {
        if (area != 0) {
            return area * price_of_paint;
        } else {
            return calc_area() * price_of_paint;
        }
    }
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
    cout << "The triangle costs " << triangle.how_much_to_paint(6) << " dollars to paint" << endl;
    cout << "The circle costs " << circle.how_much_to_paint(6) << " dollars to paint" << endl;

    return 0;
}
