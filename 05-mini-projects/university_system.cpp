#include <iostream>
using namespace std;


class person
{
protected:
    string name;
    int id;

public:
    person(string n = "unknown", int i = 0)
    {
        name = n;
        id = i;
    }

    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    virtual double calculateSalary() const = 0;

    virtual ~person() {}
};


class student : public person
{
protected:
    double* grades;
    int size;

public:
    student() : person()
    {
        grades = nullptr;
        size = 0;
    }

    student(string n, int i, double arr[], int z) : person(n, i)
    {
        size = z;
        grades = new double[size];

        for (int i = 0; i < size; i++)
        {
            grades[i] = arr[i];
        }
    }

    // Destructor
    ~student()
    {
        delete[] grades;
    }

};


int main 
{
    Student s1("Hassan", 1, grades1, 3);
Student s2("Ali", 2, grades2, 3);

Teacher t1("Dr.A", 10, 5000, 500);
Teacher t2("Dr.B", 11, 6000, 600);

Person* arr1[] = { &s1, &t1 };
Person* arr2[] = { &s2, &t2 };

University u1(arr1, 2);
University u2(arr2, 2);

University u3 = u1 + u2;

u3.printAll();

cout << "Total Salaries: " << u3.totalSalaries() << endl;

u3[0]->print();

if (u1 == u2)
    cout << "Same\n";
else
    cout << "Different\n";
    return 0;
}