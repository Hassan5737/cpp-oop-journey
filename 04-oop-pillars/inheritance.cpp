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

    void setPerson(string n, int a) {
        name = n;
        age = a;
    }

    void printPerson() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// ======================
// Derived Class
// ======================
class Student : public Person {
private:
    int grade;

public:
    Student(string n = "Unknown", int a = 0, int g = 0)
        : Person(n, a) // calling base constructor
    {
        grade = g;
    }

    void setStudent(string n, int a, int g) {
        setPerson(n, a); // reuse base function
        grade = g;
    }

    void printStudent() const {
        printPerson(); // reuse base function
        cout << "Grade: " << grade << endl;
    }
};

// ======================
// MAIN
// ======================
int main() {
    Student s1("Hassan", 21, 90);

    s1.printStudent();

    cout << "------------" << endl;

    Student s2;
    s2.setStudent("Ali", 22, 85);
    s2.printStudent();

    return 0;
}