#include <iostream>
using namespace std;

// ======================
// Base Class
// ======================
class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "Unknown", int a = 0)
    {
        name = n;
        age = a;
    }

  
    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};
class Student : public Person {
private:
    int grade;

public:
    Student(string n, int a, int g)
        : Person(n, a)
    {
        grade = g;
    }

    void print() const override
    {
        Person::print();
        cout << "Grade: " << grade << endl;
    }
};

// ======================
// Derived Class 2
// ======================
class Teacher : public Person {
private:
    double salary;

public:
    Teacher(string n, int a, double s)
        : Person(n, a)
    {
        salary = s;
    }

    void print() const override
    {
        Person::print();
        cout << "Salary: " << salary << endl;
    }
};

// ======================
// MAIN
// ======================
int main()
{
    Student s("Hassan", 21, 90);
    Teacher t("Ali", 45, 8000);

    cout << "=== Direct Call ===\n";
    s.print();
    cout << "------------\n";
    t.print();

    cout << "\n=== Polymorphism ===\n";

    Person* p;

    p = &s;
    p->print(); // calls Student print

    cout << "------------\n";

    p = &t;
    p->print(); // calls Teacher print

    cout << "------------\n";

    // Array of base pointers
    Person* people[2];
    people[0] = &s;
    people[1] = &t;

    cout << "\n=== Loop (Polymorphism) ===\n";

    for (int i = 0; i < 2; i++)
    {
        people[i]->print();
        cout << "------------\n";
    }

    return 0;
}