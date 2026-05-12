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

    Animal()
    {
        name = "Unknown";
        cout << "Animal Default Constructor Called" << endl;
    }

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

    Pet()
    {
        age = 0;
        cout << "Pet Default Constructor Called" << endl;
    }

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

    Dog() : Animal(), Pet()
    {
        cout << "Dog Default Constructor Called" << endl;
    }

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
// Example 2
// =====================================

// Base Class 1
class Engine
{
public:

    void startEngine()
    {
        cout << "Engine Started" << endl;
    }
};

// Base Class 2
class MusicSystem
{
public:

    void playMusic()
    {
        cout << "Music is Playing" << endl;
    }
};

// Derived Class
class Car : public Engine, public MusicSystem
{
public:

    void drive()
    {
        cout << "Car is Driving" << endl;
    }
};

// =====================================
// Example 3
// =====================================

// Base Class 1
class Father
{
public:

    void fatherSkill()
    {
        cout << "Father knows Fishing" << endl;
    }
};

// Base Class 2
class Mother
{
public:

    void motherSkill()
    {
        cout << "Mother knows Cooking" << endl;
    }
};

// Derived Class
class Child : public Father, public Mother
{
public:

    void childSkill()
    {
        cout << "Child knows Programming" << endl;
    }
};

// =====================================
// Main Function
// =====================================
int main()
{
    // =====================================
    // Example 1
    // =====================================

    cout << "========== Dog Example ==========\n";

    Dog dog1("Max", 5);

    dog1.eat();
    dog1.showAge();
    dog1.bark();

    cout << endl;

    // =====================================
    // Example 2
    // =====================================

    cout << "========== Car Example ==========\n";

    Car car1;

    car1.startEngine();
    car1.playMusic();
    car1.drive();

    cout << endl;

    // =====================================
    // Example 3
    // =====================================

    cout << "========== Child Example ==========\n";

    Child c1;

    c1.fatherSkill();
    c1.motherSkill();
    c1.childSkill();

    return 0;
}