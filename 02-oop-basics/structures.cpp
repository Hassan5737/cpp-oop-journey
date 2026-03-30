#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// Struct: Exam
struct Exam {
    float mid = 0;
    float final = 0;
    float practical = 0;

    float total() const {
        return mid + final + practical;
    }
};


// Struct: Student (Data + Behavior)
struct Student {
    string name;
    int id;
    Exam exam;

    // Constructor
    Student(string n, int i, float m, float f, float p)
        : name(n), id(i) {
        exam = {m, f, p};
    }

    float getTotal() const {
        return exam.total();
    }

    float getAverage() const {
        return getTotal() / 3.0;
    }

    void print() const {
        cout << "Name: " << name << "\n";
        cout << "ID: " << id << "\n";
        cout << "Mid: " << exam.mid << "\n";
        cout << "Final: " << exam.final << "\n";
        cout << "Practical: " << exam.practical << "\n";
        cout << "Total: " << getTotal() << "\n";
        cout << "Average: " << getAverage() << "\n";
        cout << "----------------------\n";
    }
};

// =========================
// Functions working with struct
// =========================

// Sort by total (Descending)
bool compareStudents(const Student& a, const Student& b) {
    return a.getTotal() > b.getTotal();
}

// Find top student
Student getTopStudent(const vector<Student>& students) {
    return *max_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getTotal() < b.getTotal();
        });
}

// =========================
// Main System
// =========================
int main() {

    vector<Student> students;

    students.emplace_back("Hassan", 1, 20, 30, 40);
    students.emplace_back("Ali", 2, 25, 35, 30);
    students.emplace_back("Omar", 3, 15, 20, 25);

    cout << "=== All Students ===\n";
    for (const auto& s : students) {
        s.print();
    }

    // Sorting
    sort(students.begin(), students.end(), compareStudents);

    cout << "\n=== After Sorting (Top First) ===\n";
    for (const auto& s : students) {
        cout << s.name << " -> " << s.getTotal() << endl;
    }

    // Top student
    Student top = getTopStudent(students);

    cout << "\n=== Top Student ===\n";
    top.print();

    return 0;
}