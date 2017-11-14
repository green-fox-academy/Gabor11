#include <iostream>
#include <string>
#include "02.h"

using namespace std;

Student::Student(string name, unsigned int age)  {
      this->age = age;
      this->name = name;
    }

int main() {
  // Create a new instance of the Student class and set it's name to "John" and
  // it's age to 21 with it's constructor

  Student stdnt("John", 21);

  cout << "This student is called " << stdnt.name << " and he is " << stdnt.age << " years old" << endl;

  return 0;
}
