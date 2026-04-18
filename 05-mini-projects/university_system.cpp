#include <iostream>
using namespace std;

// ======================
// Abstract Base Class
// ======================
class Person {
protected:
    string name;
    int id;

public:
    Person(string n = "unknown", int i = 0)
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

    virtual ~Person() {}
};

// ======================
// Student Class
// ======================
class Student : public Person {
private:
    double* grades;
    int size;

public:
    Student() : Person()
    {
        grades = nullptr;
        size = 0;
    }

    Student(string n, int i, double arr[], int z) : Person(n, i)
    {
        size = z;
        grades = new double[size];

        for (int i = 0; i < size; i++)
            grades[i] = arr[i];
    }

    // Copy Constructor (Deep Copy)
    Student(const Student& other) : Person(other)
    {
        size = other.size;
        grades = new double[size];

        for (int i = 0; i < size; i++)
            grades[i] = other.grades[i];
    }

    double averageGrade() const
    {
        if (size == 0) return 0;

        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += grades[i];

        return sum / size;
    }

    void print() const override
    {
        Person::print();

        cout << "Grades: ";
        for (int i = 0; i < size; i++)
            cout << grades[i] << " ";

        cout << "\nAverage: " << averageGrade() << endl;
    }

    double calculateSalary() const override
    {
        return 0;
    }

    ~Student()
    {
        delete[] grades;
    }
};

// ======================
// Teacher Class
// ======================
class Teacher : public Person {
private:
    double salary;
    double bonus;

public:
    Teacher(string n, int i, double s, double b) : Person(n, i)
    {
        salary = s;
        bonus = b;
    }

    void print() const override
    {
        Person::print();
        cout << "Salary: " << salary << endl;
        cout << "Bonus: " << bonus << endl;
    }

    double calculateSalary() const override
    {
        return salary + bonus;
    }
};

// ======================
// University Class
// ======================
class University {
private:
    Person** people;
    int size;

public:
    // Default Constructor
    University()
    {
        people = nullptr;
        size = 0;
    }

    // Parameterized Constructor
    University(Person* arr[], int s)
    {
        size = s;
        people = new Person*[size];

        for (int i = 0; i < size; i++)
            people[i] = arr[i]; // shallow copy (intentional)
    }

    // Destructor
    ~University()
    {
        delete[] people;
    }

    // Print all
    void printAll() const
    {
        for (int i = 0; i < size; i++)
        {
            people[i]->print();
            cout << "------------\n";
        }
    }

    // Total Salaries
    double totalSalaries() const
    {
        double sum = 0;

        for (int i = 0; i < size; i++)
            sum += people[i]->calculateSalary();

        return sum;
    }


    University operator+(const University& other) const
    {
        University result;

        result.size = size + other.size;
        result.people = new Person*[result.size];

        for (int i = 0; i < size; i++)
            result.people[i] = people[i];

        for (int i = 0; i < other.size; i++)
            result.people[i + size] = other.people[i];

        return result;
    }

   
    Person* operator[](int index)
    {
        return people[index];
    }

    // Operator ==
    bool operator==(const University& other) const
    {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++)
        {
            if (people[i] != other.people[i])
                return false;
        }

        return true;
    }
};

// ======================
// MAIN
// ======================
int main()
{
    double g1[] = {80, 90, 85};
    double g2[] = {70, 60, 75};

    Student s1("Hassan", 1, g1, 3);
    Student s2("Ali", 2, g2, 3);

    Teacher t1("Dr.A", 10, 5000, 500);
    Teacher t2("Dr.B", 11, 6000, 600);

    Person* arr1[] = { &s1, &t1 };
    Person* arr2[] = { &s2, &t2 };

    University u1(arr1, 2);
    University u2(arr2, 2);

    University u3 = u1 + u2;

    cout << "=== All People ===\n";
    u3.printAll();

    cout << "Total Salaries: " << u3.totalSalaries() << endl;

    cout << "\nFirst Person:\n";
    u3[0]->print();

    if (u1 == u2)
        cout << "\nSame\n";
    else
        cout << "\nDifferent\n";

    return 0;
}