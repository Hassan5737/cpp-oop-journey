#include <iostream>
using namespace std;

// =====================================
// Base Class (Parent)
// =====================================
class Animal
{
protected:
    string name;

public:

    // Default Constructor
    Animal()
    {
        name = "Unknown";
        cout << "Animal Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Animal(string n)
    {
        name = n;
        cout << "Animal Parameterized Constructor Called" << endl;
    }

    void eat()
    {
        cout << name << " is eating" << endl;
    }
};

// =====================================
// Derived Class (Child)
// Public Inheritance
// =====================================
class Dog : public Animal
{
public:

    // Default Constructor
    Dog() : Animal()
    {
        cout << "Dog Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Dog(string n) : Animal(n)
    {
        cout << "Dog Parameterized Constructor Called" << endl;
    }

    void bark()
    {
        cout << name << " says: Woof Woof" << endl;
    }
};

int main()
{
    cout << "===== Default Object =====" << endl;

    Dog dog1;

    dog1.eat();   // inherited from Animal
    dog1.bark();

    cout << endl;

    cout << "===== Parameterized Object =====" << endl;

    Dog dog2("Max");

    dog2.eat();   // inherited from Animal
    dog2.bark();

    return 0;
}