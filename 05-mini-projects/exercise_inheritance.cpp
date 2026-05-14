#include <iostream>
using namespace std;

/*
=========================================================
                    INHERITANCE IN C++
=========================================================

Inheritance allows a class to inherit properties
and functions from another class.

Benefits:
1) Code Reusability
2) Better Organization
3) Relationship Between Classes

=========================================================
Types of Inheritance:
=========================================================

1) Single Inheritance
2) Multiple Inheritance
3) Hierarchical Inheritance
4) Multilevel Inheritance

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
