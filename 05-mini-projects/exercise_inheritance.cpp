#include <iostream>
using namespace std;

// =====================================
// Base Class
// =====================================
class Animal
{
public:

    // Virtual Function
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }
};
// =====================================
// Derived Class
// =====================================
class Dog : public Animal
{
public:

    // Override Function
    void makeSound() override
    {
        cout << "Dog says: Woof Woof" << endl;
    }
};

// =====================================
// Another Derived Class
// =====================================
class Cat : public Animal
{
public:

    // Override Function
    void makeSound() override
    {
        cout << "Cat says: Meow Meow" << endl;
    }
};