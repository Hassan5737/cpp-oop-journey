#include <iostream>
using namespace std;

// =====================================
// Base Class 1
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
// Base Class 2
// =====================================
class Pet
{
protected:
    int age;

public:

    // Default Constructor
    Pet()
    {
        age = 0;
        cout << "Pet Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Pet(int a)
    {
        age = a;
        cout << "Pet Parameterized Constructor Called" << endl;
    }

    void showAge()
    {
        cout << "Age: " << age << endl;
    }
};

// =====================================
// Derived Class
// Multiple Inheritance
// =====================================
class Dog : public Animal, public Pet
{
public:

    // Default Constructor
    Dog() : Animal(), Pet()
    {
        cout << "Dog Default Constructor Called" << endl;
    }

    // Parameterized Constructor
    Dog(string n, int a) : Animal(n), Pet(a)
    {
        cout << "Dog Parameterized Constructor Called" << endl;
    }

    void bark()
    {
        cout << name << " says: Woof Woof" << endl;
    }
};

// =====================================
// Main Function
// =====================================
int main()
{
    cout << "===== Default Object =====" << endl;

    Dog dog1;

    dog1.eat();
    dog1.showAge();
    dog1.bark();

    cout << endl;

    cout << "===== Parameterized Object =====" << endl;

    Dog dog2("Max", 5);

    dog2.eat();
    dog2.showAge();
    dog2.bark();

    return 0;
}