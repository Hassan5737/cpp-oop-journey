#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    int mark;

public:
    // Parameterized Constructor
    Student(string n, int m)
    {
        name = n;
        mark = m;
    }

    // Default Constructor
    Student()
    {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter student mark: ";
        cin >> mark;
    }

    // Display Student Data
    void display() const
    {
        cout << "Name : " << name << endl;
        cout << "Mark : " << mark << endl;
    }

    // Compare Marks
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

    // Friend Function
    friend int sumMarks(const Student& s1,
                        const Student& s2,
                        const Student& s3);
};

// Friend Function Definition
int sumMarks(const Student& s1,
             const Student& s2,
             const Student& s3)
{
    return s1.mark + s2.mark + s3.mark;
}

int main()
{
    Student s1("Ahmed", 50);
    Student s2("Ali", 60);
    Student s3("Nour", 100);

    cout << "===== Students Data =====\n\n";

    s1.display();
    cout << endl;

    s2.display();
    cout << endl;

    s3.display();
    cout << endl;

    cout << "=========================\n\n";

    cout << "Total Marks = "
         << sumMarks(s1, s2, s3)
         << endl << endl;

    Student::checkHighestMark(s1, s2, s3);

    return 0;
}