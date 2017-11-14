#ifndef _03_H
#define _03_H
#include <string>

using namespace std;

class Student {
  public:
    string name;
    unsigned int age;
    Student(string name, unsigned int age);
    string greet();

};

#endif // _03_H
