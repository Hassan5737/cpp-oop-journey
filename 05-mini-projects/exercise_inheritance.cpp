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

class Engine
{
public:

    void startEngine()
    {
        cout << "Engine Started" << endl;
    }
};

class MusicSystem
{
public:

    void playMusic()
    {
        cout << "Music Playing" << endl;
    }
};

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

class LivingThing
{
public:

    void breathe()
    {
        cout << "Living thing is breathing" << endl;
    }
};

class Mammal : public LivingThing
{
public:

    void walk()
    {
        cout << "Mammal is walking" << endl;
    }
};

class Human : public Mammal
{
public:

    void speak()
    {
        cout << "Human is speaking" << endl;
    }
};



// =====================================================
// 5) FUNCTION OVERRIDING
// =====================================================

/*
Function Overriding happens when
a child class redefines a function
from the parent class.
*/

class Employee
{
public:

    virtual void work()
    {
        cout << "Employee is working" << endl;
    }
};

class Programmer : public Employee
{
public:

    void work() override
    {
        cout << "Programmer is writing code" << endl;
    }
};



// =====================================================
// 6) FRIEND FUNCTION
// =====================================================

/*
A friend function can access
private members of a class.
*/

class BankAccount
{
private:
    string owner;
    double balance;

public:

    BankAccount(string o, double b)
    {
        owner = o;
        balance = b;
    }

    // Friend Function Declaration
    friend void showAccount(BankAccount acc);
};

// Friend Function Definition
void showAccount(BankAccount acc)
{
    cout << "Owner: " << acc.owner << endl;
    cout << "Balance: " << acc.balance << endl;
}




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


    cout << endl;
    cout << "==============================" << endl;
    cout << "Function Overriding" << endl;
    cout << "==============================" << endl;

    Programmer p1;

    p1.work();


    cout << endl;
    cout << "==============================" << endl;
    cout << "Friend Function" << endl;
    cout << "==============================" << endl;

    BankAccount acc1("Hassan", 5000);

    showAccount(acc1);


    return 0;
}