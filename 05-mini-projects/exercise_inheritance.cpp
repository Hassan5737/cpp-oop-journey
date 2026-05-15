#include <iostream>
using namespace std;

/*
=========================================================
                    INHERITANCE IN C++
=========================================================

Topics Included:
1) Single Inheritance
2) Multiple Inheritance
3) Hierarchical Inheritance
4) Multilevel Inheritance
5) Function Overriding
6) Friend Function

=========================================================
*/
// =====================================================
// 1) SINGLE INHERITANCE
// =====================================================

// Parent Class
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
        cout << name << " is eating" << endl;
    }
};

// Child Class
class Dog : public Animal
{
public:

    Dog(string n) : Animal(n)
    {
    }

    void bark()
    {
        cout << name << " is barking" << endl;
    }
};

// =====================================================
// 2) MULTIPLE INHERITANCE
// =====================================================

/*
A class inherits from more than one class
*/

// First Parent
class Engine
{
public:

    void startEngine()
    {
        cout << "Engine Started" << endl;
    }
};

// Second Parent
class MusicSystem
{
public:

    void playMusic()
    {
        cout << "Music Playing" << endl;
    }
};

// Child Class
class Car : public Engine, public MusicSystem
{
public:

    void drive()
    {
        cout << "Car is Driving" << endl;
    }
};

// =====================================================
// 3) HIERARCHICAL INHERITANCE
// =====================================================

/*
Multiple child classes inherit
from the same parent class
*/

// Parent Class
class Person
{
protected:
    string personName;

public:

    Person(string n)
    {
        personName = n;
    }

    void introduce()
    {
        cout << "My name is " << personName << endl;
    }
};

// First Child
class Student : public Person
{
public:

    Student(string n) : Person(n)
    {
    }

    void study()
    {
        cout << personName << " is studying" << endl;
    }
};

// Second Child
class Teacher : public Person
{
public:

    Teacher(string n) : Person(n)
    {
    }

    void teach()
    {
        cout << personName << " is teaching" << endl;
    }
};


// =====================================================
// 4) MULTILEVEL INHERITANCE
// =====================================================

/*
Inheritance through multiple levels

Grandparent -> Parent -> Child
*/

// Grandparent
class LivingThing
{
public:

    void breathe()
    {
        cout << "Living thing is breathing" << endl;
    }
};

// Parent
class Mammal : public LivingThing
{
public:

    void walk()
    {
        cout << "Mammal is walking" << endl;
    }
};

// Child
class Human : public Mammal
{
public:

    void speak()
    {
        cout << "Human is speaking" << endl;
    }
};

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    cout << "==============================" << endl;
    cout << "Single Inheritance" << endl;
    cout << "==============================" << endl;

    Dog dog1("Rocky");

    dog1.eat();
    dog1.bark();


    cout << endl;
    cout << "==============================" << endl;
    cout << "Multiple Inheritance" << endl;
    cout << "==============================" << endl;

    Car car1;

    car1.startEngine();
    car1.playMusic();
    car1.drive();


    cout << endl;
    cout << "==============================" << endl;
    cout << "Hierarchical Inheritance" << endl;
    cout << "==============================" << endl;

    Student s1("Hassan");
    Teacher t1("Ahmed");

    s1.introduce();
    s1.study();

    cout << endl;

    t1.introduce();
    t1.teach();


    cout << endl;
    cout << "==============================" << endl;
    cout << "Multilevel Inheritance" << endl;
    cout << "==============================" << endl;

    Human h1;

    h1.breathe();
    h1.walk();
    h1.speak();


    return 0;
}