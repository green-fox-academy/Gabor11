#include <iostream>
#include <string>
#include "01.h"

using namespace std;

int main() {
  // Create a new instance of the Student class and set it's name to "John" and
  // it's age to 21

  Student stdnt;

  stdnt.name = "John";
  stdnt.age = 21;

  cout << "This student is called " << stdnt.name << " and he is " << stdnt.age << " years old" << endl;

  return 0;
}
