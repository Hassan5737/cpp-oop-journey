#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
private:
    string name;
    int mark;

    static int studentsCount;

public:
    // Default Constructor
    Student()
    {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student mark: ";
        cin >> mark;

        studentsCount++;
    }

    // Parameterized Constructor
    Student(string n, int m)
    {
        name = n;
        setMark(m);

        studentsCount++;
    }

    // Copy Constructor
    Student(const Student& other)
    {
        name = other.name;
        mark = other.mark;

        studentsCount++;
    }

    // Destructor
    ~Student()
    {
        cout << "Object for " << name << " destroyed.\n";
    }

    // Setter
    void setMark(int m)
    {
        if (m >= 0 && m <= 100)
            mark = m;
        else
        {
            cout << "Invalid mark. Mark set to 0.\n";
            mark = 0;
        }
    }

    // Getter
    int getMark() const
    {
        return mark;
    }

    string getName() const
    {
        return name;
    }

    // Display Student Data
    void display() const
    {
        cout << left << setw(10) << name
             << " | Mark: " << mark << endl;
    }

    // Grade Function
    char getGrade() const
    {
        if (mark >= 90)
            return 'A';

        else if (mark >= 80)
            return 'B';

        else if (mark >= 70)
            return 'C';

        else if (mark >= 60)
            return 'D';

        return 'F';
    }

    // Check Pass or Fail
    void checkStatus() const
    {
        if (mark >= 50)
            cout << name << " Passed.\n";
        else
            cout << name << " Failed.\n";
    }

    // Static Function
    static int getStudentsCount()
    {
        return studentsCount;
    }

    // Highest Mark
    static void checkHighestMark(const Student& s1,
                                 const Student& s2,
                                 const Student& s3)
    {
        if (s1.mark > s2.mark && s1.mark > s3.mark)
            cout << s1.name << " has the highest mark.\n";

        else if (s2.mark > s1.mark && s2.mark > s3.mark)
            cout << s2.name << " has the highest mark.\n";

        else if (s3.mark > s1.mark && s3.mark > s2.mark)
            cout << s3.name << " has the highest mark.\n";

        else
            cout << "There is a tie between students.\n";
    }

    // Operator Overloading
    bool operator>(const Student& other) const
    {
        return mark > other.mark;
    }

    // Friend Function
    friend int sumMarks(const Student& s1,
                        const Student& s2,
                        const Student& s3);

    friend double averageMarks(const Student& s1,
                               const Student& s2,
                               const Student& s3);
};

// Static Variable Definition
int Student::studentsCount = 0;

// Friend Function
int sumMarks(const Student& s1,
             const Student& s2,
             const Student& s3)
{
    return s1.mark + s2.mark + s3.mark;
}

// Friend Function
double averageMarks(const Student& s1,
                    const Student& s2,
                    const Student& s3)
{
    return sumMarks(s1, s2, s3) / 3.0;
}

int main()
{
    Student s1("Ahmed", 95);
    Student s2("Ali", 70);
    Student s3("Nour", 40);

    cout << "\n===== Students Data =====\n\n";

    s1.display();
    cout << "Grade: " << s1.getGrade() << endl;
    s1.checkStatus();

    cout << endl;

    s2.display();
    cout << "Grade: " << s2.getGrade() << endl;
    s2.checkStatus();

    cout << endl;

    s3.display();
    cout << "Grade: " << s3.getGrade() << endl;
    s3.checkStatus();

    cout << "\n=========================\n\n";

    cout << "Total Marks = "
         << sumMarks(s1, s2, s3)
         << endl;

    cout << "Average Marks = "
         << averageMarks(s1, s2, s3)
         << endl << endl;

    Student::checkHighestMark(s1, s2, s3);

    cout << endl;

    if (s1 > s2)
        cout << s1.getName()
             << " has higher marks than "
             << s2.getName() << endl;

    cout << "\nTotal Students Objects = "
         << Student::getStudentsCount()
         << endl;

    return 0;
}