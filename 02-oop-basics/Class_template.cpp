#include <iostream>
using namespace std;

// =========================
// 1. Template Function
// =========================
template <typename T>
T add(T a, T b)
{
    return a + b;
}

// =========================
// 2. Multiple Parameters
// =========================
template <typename T1, typename T2>
void printPair(T1 a, T2 b)
{
    cout << "Pair: " << a << " , " << b << endl;
}

// =========================
// 3. Class Template
// =========================
template <typename T>
class Box
{
private:
    T value;

public:
    Box(T v) : value(v) {}

    void setValue(T v)
    {
        value = v;
    }

    T getValue() const
    {
        return value;
    }
};

// =========================
// 4. Template Specialization
// =========================
template <typename T>
class Printer
{
public:
    void print(T value)
    {
        cout << "Generic: " << value << endl;
    }
};

// Specialization for string
template <>
class Printer<string>
{
public:
    void print(string value)
    {
        cout << "String Special: " << value << endl;
    }
};

// =========================
// MAIN
// =========================
int main()
{
    // Template Function
    cout << "Add int: " << add(3, 5) << endl;
    cout << "Add double: " << add(2.5, 3.1) << endl;

    // Multiple Parameters
    printPair(10, "Hassan");
    printPair(3.14, 7);

    // Class Template
    Box<int> intBox(100);
    Box<string> strBox("Hello");

    cout << "Int Box: " << intBox.getValue() << endl;
    cout << "String Box: " << strBox.getValue() << endl;

    // Template Specialization
    Printer<int> p1;
    Printer<string> p2;

    p1.print(50);
    p2.print("Hassan Ahmed");

    return 0;
}