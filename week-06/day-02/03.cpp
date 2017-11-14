#include <iostream>
#include <string>
#include "03.h"

using namespace std;

Student::Student(string name, unsigned int age)
{
    this->age = age;
    this->name = name;
}

string Student::greet()
{
    return "Hello my name is " + name;
}

int main() {
  // Create a method on the Student class called "greet" that returns a string
  // like: "Hello my name is: <student name>"

  Student stdnt("John", 21);
  cout << stdnt.greet();

  return 0;
}
