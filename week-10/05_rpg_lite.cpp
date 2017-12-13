#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

class Character {
private:
protected:

    char type;
    int health;
    int attack;
    int defense;
public:
    string name;
    Character(string name, int health, int attack, int defense, char type)
    {
        this->name = name;
        this->health = health;
        this->attack = attack;
        this->defense = defense;
        this->type = type;
    }
    void Attack(Character *enemy)
    {
        int temp_attack;
        if (rand()%100 > 49)
            temp_attack = 2 * attack;
        else
            temp_attack = attack;

        if (temp_attack > enemy->get_defense())
            enemy->set_health(enemy->get_health() - (temp_attack - enemy->get_defense()));
        else
            set_health(health - (enemy->get_defense() - temp_attack));
    }

    void set_health(int set_value)
    {
        if (set_value >= 0)
            health = set_value;
        else if (set_value < 0)
            health = 0;
    }

    int get_health()
    {
        return health;
    }

    int get_defense()
    {
        return defense;
    }

};

void delay(uint8_t sec)
{
    uint8_t time = 32767; //sec * 8200;
    for (int i = 1 ; i <= 15000 ; i++ )
        for (int j = 1 ; j <= 15000 ; j++ )
        {}
}

int main() {
    //RPG Game lite
    //Create a Character class with the following preferences:
    //name
    //character type (player/monster)
    //health point value
    //attack value
    //defense value
    //attacking method which takes a character class and decreases its health
    //value with (current character class attack - input character class defense),
    //if the output is minus, then our health is decreased
    //set the attacking method to have 50% chanse to count our attack value twice,
    //(2xcurrent attack - input defense) before calculating the final health points.

    //create 2 instances of the character class and fill their base stats from their constructor
    //make them attack each other with the attack method from the character class
    //after each round print both the attacker, and the attacked character health
    //make them fight each other until one of them has a health point lower or equal 0
    //print the winner and offer a new game

    //dont forget to use private variables, and get/set methods, and also place out_of_range
    //character class into a seperate file

    Character Magician("Harry", 100, 15, 16, 'p');
    Character Evil_Magician("Voldemort", 100, 15, 16, 'p');
    int i = 1;
    while (Magician.get_health() > 0 && Evil_Magician.get_health() > 0)
    {
        Magician.Attack(&Evil_Magician);
        Evil_Magician.Attack(&Magician);
        cout << "Round " << i << ": " << endl;
        cout << Magician.name << " " << (int)Magician.get_health() << "HP" << endl;
        cout << Evil_Magician.name << " " << (int)Evil_Magician.get_health() << "HP" << endl;
        delay(10);
        i++;
    }
    if (Evil_Magician.get_health() > 0)
        cout << "The winner is " << Evil_Magician.name << endl;
    else
        cout << "The winner is " << Magician.name << endl;


  return 0;
}


