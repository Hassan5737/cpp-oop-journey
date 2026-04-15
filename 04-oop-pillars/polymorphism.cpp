#include <iostream>
using namespace std;

// Abstract Base Class
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

    // Virtual function
    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Pure Virtual Function (Abstraction)
    virtual void work() const = 0;

    // Virtual Destructor
    virtual ~Person()
    {
        cout << "Person destroyed\n";
    }
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

    void work() const override
    {
        cout << name << " is studying..." << endl;
    }

    ~Student()
    {
        cout << "Student destroyed\n";
    }
};



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

    void work() const override
    {
        cout << name << " is teaching..." << endl;
    }

    ~Teacher()
    {
        cout << "Teacher destroyed\n";
    }
};


int main()
{
    // Polymorphism with dynamic allocation
    Person* p1 = new Student("Hassan", 21, 90);
    Person* p2 = new Teacher("Ali", 45, 8000);

    cout << "=== Polymorphism ===\n";

    p1->print();
    p1->work();

    cout << "------------\n";

    p2->print();
    p2->work();

    cout << "------------\n";

    // Array of base pointers
    Person* people[2];
    people[0] = p1;
    people[1] = p2;

    cout << "\n=== Loop ===\n";

    for (int i = 0; i < 2; i++)
    {
        people[i]->print();
        people[i]->work();
        cout << "------------\n";
    }

    // Clean up
    delete p1;
    delete p2;

    return 0;
}