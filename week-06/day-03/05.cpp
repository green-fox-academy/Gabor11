#include <iostream>
#include <vector>

using namespace std;

// Create a Car class.
// Create the following private variables : age, kms_runed, manufacturer, number_of_seats
// use proper variable types.
// Implement a method which has one parameter, and increases the kms_runed variable by its parameter value.
// Implement a method which can add a person to a car, if the number of persons in the car reached
// the value of number of seats in the car it should tell you that 'The car is full!' or something like that.
// Inherite at least two car models and try out the methods you have created.

class Car {
protected:
    int age;
    int kms_run;
    string manufacturer;
    int number_of_seats;
    int number_of_people;

public:
    Car(int age, int kms_run, string manufacturer, int number_of_seats, int number_of_people)
    {
        this->age = age;
        this->kms_run = kms_run;
        this->manufacturer = manufacturer;
        this->number_of_people = number_of_people;
        this->number_of_seats = number_of_seats;

    }

    void run(int kms)
    {
        if (kms > 0)
            kms_run += kms;
        else
            cout << "invalid input" << endl;
    }
    void get_in_the_car(int no_of_ppl)
    {
        if (no_of_ppl < 0)
            cout << "invalid input" << endl;
        else if (no_of_ppl > number_of_seats)
            cout << "no enough space in the car" << endl;
        else {
            cout << "Number of people got in: " << no_of_ppl << endl;
            number_of_people += no_of_ppl;
            number_of_seats -= no_of_ppl;

        }
        if (number_of_seats == 0)
            cout << "The car is full!!" << endl;

    }
    void get_out_the_car(int no_of_ppl)
    {
        if (no_of_ppl < 0)
            cout << "invalid input" << endl;
        else if (no_of_ppl > number_of_people)
            cout << "not so many people in the car" << endl;
        else {
            cout << "Number of people got out: " << no_of_ppl << endl;
            number_of_people -= no_of_ppl;
            number_of_seats += no_of_ppl;
        }

    }

    int get_age()
    {
        return age;
    }

    int get_kms()
    {
        return kms_run;
    }

    int get_number_of_people()
    {
        return number_of_people;
    }

    int get_number_of_seats()
    {
        return number_of_seats;
    }
};

class VW: public Car {
public:
    VW(int age, int kms_run, int number_of_seats, int number_of_people) : Car(age, kms_run, "VW", number_of_seats, number_of_people)
    {
        cout << "Das Auto" << endl;
    }
};

class BMW: public Car {
public:
    BMW(int age, int kms_run, int number_of_seats, int number_of_people) : Car(age, kms_run, "BMW", number_of_seats, number_of_people)
    {
        cout << "The ultimate driving machine" << endl;
    }
};

int main()
{
    BMW bmw(0, 0, 5, 0);
    VW vw(0, 0, 5, 0);

    bmw.get_in_the_car(5);
    bmw.get_in_the_car(1);
    bmw.run(5);

    cout << "This BMW run " << bmw.get_kms() << " kms" << endl;
    cout << "number of passengers: " << bmw.get_number_of_people() << endl;

    vw.get_in_the_car(3);
    vw.run(7);

    cout << "This VW run " << vw.get_kms() << " kms" << endl;
    cout << "number of passengers: " << vw.get_number_of_people() << endl;

    cout << vw.get_age() << endl;

    return 0;
}
