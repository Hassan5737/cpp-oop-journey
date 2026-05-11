#include <iostream>
using namespace std;

// ===============================
// Base Class (Parent)
// ===============================
class Animal
{
protected:
    string name;

public:
    Animal(string n)
    {
        name = n;
    }

    void eat()
    {
        cout << name << " is eating 🍖" << endl;
    }
};

// ===============================
// Derived Class (Child)
// Single Inheritance
// Dog inherits from Animal
// ===============================
class Dog : public Animal
{
public:
    Dog(string n) : Animal(n)
    {
    }

    void bark()
    {
        cout << name << " says: Woof Woof! 🐶" << endl;
    }
};

int main()
{
    Dog dog1("Max");

    dog1.eat();   // inherited from Animal
    dog1.bark();  // from Dog

    return 0;
}