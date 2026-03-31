#include <iostream>
#include <cstring>
using namespace std;

class Student
{
private:
    char* name;
    int* grades;
    int size;

public:

    // Constructor
    Student(const char* n, int s)
    {
        size = s;

        // allocate name
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        // allocate grades
        grades = new int[size];

        for (int i = 0; i < size; i++)
            grades[i] = 0;
    }

    // set grade
    void setGrade(int index, int value)
    {
        if (index >= 0 && index < size)
            grades[index] = value;
    }

    // print data
    void print()
    {
        cout << "Name: " << name << endl;
        cout << "Grades: ";

        for (int i = 0; i < size; i++)
            cout << grades[i] << " ";

        cout << endl;
    }

    // Destructor
    ~Student()
    {
        delete[] name;
        delete[] grades;

        cout << "Destructor called for " << name << endl;
    }
};

int main()
{
    Student s1("Hassan", 3);

    s1.setGrade(0, 90);
    s1.setGrade(1, 85);
    s1.setGrade(2, 100);

    s1.print();

    return 0;
}