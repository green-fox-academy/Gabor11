#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(string _name)
    {
        name = _name;
    }

    string getName()
    {
        return name;
    }
    void setName(string _name)
    {
        name = _name;
    }
};

//TODO: create a class called Mammal inherited from Animal
//extend it with to functions
//the one is 'Feed' which prints out 'Feeding...'
//the other is 'Sleep' which prints out 'Sleeping...'

class Mammal : public Animal
{
public:
    Mammal(string _name) : Animal(_name) {}
    feed()
    {
        cout << "Feeding ..." << endl;
    }
    sleep()
    {
        cout << "Sleeping ..." << endl;
    }

};

//after that create another class called Fox
//extend it with a string data member called 'furcoat'
//then extend it with 'getFurCoat' and 'setFurCoat' methods

class Fox : public Mammal{
    private:
    string furcoat;
    public:
    Fox(string _name) : Mammal(_name) {}
    string get_furcoat()
    {
        return furcoat;
    }
    void set_furcoat(string _furcoat)
    {
        furcoat = _furcoat;
    }

};


int main()
{
    //create a fox object and call all of its functions (all in all 7 including the constructor)

    Fox maxy("mamy");

    cout << maxy.getName() << endl;
    maxy.setName("miney");
    cout << "my new name is: " << maxy.getName() << endl;
    maxy.set_furcoat("red");
    cout << "My furcoat is: " << maxy.get_furcoat() << endl;
    maxy.feed();
    maxy.sleep();

    return 0;
}
