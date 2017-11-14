#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
    vector <int> grades;
public:
    void add_grade(int grade)
    {
        if (grade < 6 && grade > 0) {
            grades.push_back(grade);
        } else {
            cout << "Please insert a grade from 1 to 5" << endl;
        }
    }
    double get_average()
    {
        double sum = 0;
        for (int i = 0; i < grades.size(); ++i) {
            sum += grades[i];
        }
        return sum / grades.size();
    }
};

int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades

    Student stdnt;
    stdnt.add_grade(4);
    stdnt.add_grade(3);
    stdnt.add_grade(4);
    stdnt.add_grade(5);
    stdnt.add_grade(2);
    stdnt.add_grade(6);
    cout << stdnt.get_average() << endl;



    return 0;
}
