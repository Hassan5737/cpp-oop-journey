#include <iostream>
#include <cstring>
using namespace std;

// ======================
//  Class with Dynamic Memory
// ======================
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

        name = new char[strlen(n) + 1];
        strcpy(name, n);

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

    // print
    void print() const
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
        cout << "Destructor called for " << name << endl;

        delete[] name;
        delete[] grades;
    }
};

// ======================
// Main
// ======================
int main()
{
    cout << "===== POINTER BASICS =====\n";

    int var1 = 11;
    int var2 = 22;

    cout << "Address of var1: " << &var1 << endl;
    cout << "Address of var2: " << &var2 << endl;

    int* ptr = &var2;

    cout << "Value before: " << var2 << endl;

    *ptr = 5000; // modify through pointer

    cout << "Value after: " << var2 << endl;


    cout << "\n===== DYNAMIC MEMORY =====\n";

    int* p = new int;
    *p = 100;

    cout << "Heap value: " << *p << endl;

    delete p;


    cout << "\n===== DYNAMIC ARRAY =====\n";

    int size = 3;
    int* arr = new int[size];

    for (int i = 0; i < size; i++)
        arr[i] = (i + 1) * 10;

    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;

    delete[] arr;


    cout << "\n===== CLASS WITH POINTERS =====\n";

    Student s1("Hassan", 3);

    s1.setGrade(0, 90);
    s1.setGrade(1, 85);
    s1.setGrade(2, 100);

    s1.print();

    return 0;
}