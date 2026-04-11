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
    Person(string n = "Unknown", int a = 0) {
        name = n;
        age = a;
    }

    virtual void print() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

// ======================
// Derived Class 1
// ======================
class Student : public Person {
protected:
    int grade;

public:
    Student(string n = "Unknown", int a = 0, int g = 0)
        : Person(n, a)
    {
        grade = g;
    }

    void print() const override {
        Person::print();
        cout << "Grade: " << grade << endl;
    }
};

// ======================
// Derived Class 2
// ======================
class Teacher : public Person {
protected:
    double salary;

public:
    Teacher(string n = "Unknown", int a = 0, double s = 0)
        : Person(n, a)
    {
        salary = s;
    }

    void print() const override {
        Person::print();
        cout << "Salary: " << salary << endl;
    }
};


class Assistant : public Student, public Teacher {
private:
    int hours;

public:
    Assistant(string n, int a, int g, double s, int h)
        : Student(n, a, g), Teacher(n, a, s)
    {
        hours = h;
    }

    void print() const {
     
        Student::print();
        cout << "Salary: " << salary << endl;
        cout << "Working Hours: " << hours << endl;
    }
};

// ======================
// MAIN
// ======================
int main() {

    cout << "=== Student ===\n";
    Student s("Hassan", 21, 90);
    s.print();

    cout << "\n=== Teacher ===\n";
    Teacher t("Dr.Ali", 45, 8000);
    t.print();

    cout << "\n=== Polymorphism ===\n";
    Person* p;

    p = &s;
    p->print(); // calls Student print

    p = &t;
    p->print(); // calls Teacher print

    cout << "\n=== Assistant (Multiple Inheritance) ===\n";
    Assistant a("Omar", 23, 85, 3000, 20);
    a.print();

    return 0;
}