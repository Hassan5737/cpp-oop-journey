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

int main()
{
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();

    animal1->makeSound();
    animal2->makeSound();

    delete animal1;
    delete animal2;

    return 0;
}