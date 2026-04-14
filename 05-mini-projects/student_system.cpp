#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int id;
    double* grades;
    int size;

public:
  
    Student()
        : name("unknown"), id(0), grades(nullptr), size(0) {}

   
    Student(string n, int d, double arr[], int z)
        : name(n), id(d), size(z)
    {
        grades = new double[size];

        for (int i = 0; i < size; i++)
            grades[i] = arr[i];
    }

    Student(const Student& other)
        : name(other.name), id(other.id), size(other.size)
    {
        grades = new double[size];

        for (int i = 0; i < size; i++)
            grades[i] = other.grades[i];
    }

   
    Student& operator=(const Student& other)
    {
        if (this == &other)
            return *this;

        delete[] grades;

        name = other.name;
        id = other.id;
        size = other.size;

        grades = new double[size];

        for (int i = 0; i < size; i++)
            grades[i] = other.grades[i];

        return *this;
    }

   
    Student(Student&& other) noexcept
    {
        name = other.name;
        id = other.id;
        size = other.size;
        grades = other.grades;

        other.grades = nullptr;
        other.size = 0;
    }

  
    Student& operator=(Student&& other) noexcept
    {
        if (this == &other)
            return *this;

        delete[] grades;

        name = other.name;
        id = other.id;
        size = other.size;
        grades = other.grades;

        other.grades = nullptr;
        other.size = 0;

        return *this;
    }

    void print() const
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;

        cout << "Grades: ";
        for (int i = 0; i < size; i++)
            cout << grades[i] << " ";

        cout << endl;
    }

    double average() const
    {
        if (size == 0) return 0;

        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += grades[i];

        return sum / size;
    }


    Student operator+(const Student& other) const
    {
        if (size != other.size)
        {
            cout << "Error: size mismatch\n";
            return Student();
        }

        Student result(name, id, grades, size);

        for (int i = 0; i < size; i++)
            result.grades[i] += other.grades[i];

        return result;
    }

    friend bool operator==(const Student& a, const Student& b)
    {
        return a.id == b.id;
    }

    ~Student()
    {
        delete[] grades;
    }
};


int main()
{
    double g1[] = {80, 90, 85};
    double g2[] = {70, 60, 75};

    Student s1("Hassan", 1, g1, 3);
    Student s2("Ali", 2, g2, 3);

    Student s3 = s1 + s2;

    s1.print();
    s2.print();
    s3.print();

    if (s1 == s2)
        cout << "Same student\n";
    else
        cout << "Different\n";

    cout << "Average s1: " << s1.average() << endl;
    cout << "Average s2: " << s2.average() << endl;

    return 0;
}