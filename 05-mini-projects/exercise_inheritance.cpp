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