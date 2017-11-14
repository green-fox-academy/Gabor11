#include <iostream>

using namespace std;

// An average Green Fox attendee codes 6 hours daily
// The semester is 17 weeks long
//
// Print how many hours is spent with coding in a semester by an attendee,
// if the attendee only codes on workdays.
//
// Print the percentage of the coding hours in the semester if the average
// work hours weekly is 52

int main()
{
    int weeks = 17;
    int coding_hours_per_day = 6;
    int workdays = 5;
    int weekly_workhours = 52;
    double percent = (double)coding_hours_per_day * workdays *100 / weekly_workhours;

    cout.precision(2);

    cout << "Working hours spent with coding in a semester by an attendee: " << weeks * coding_hours_per_day * workdays << endl;

    cout << "Percentage of coding hours: " << fixed << percent << " %" << endl;
    return 0;
}
