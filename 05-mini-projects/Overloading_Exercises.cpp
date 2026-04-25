#include <iostream>
using namespace std;

/*
========================================
        FUNCTION OVERLOADING
========================================
*/

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

/*
========================================
        CLASS WITH OVERLOADING
========================================
*/

class Vector2D
{
private:
    double x, y;

public:
    // Constructor Overloading
    Vector2D()
    {
        x = 0;
        y = 0;
    }

    Vector2D(double val)
    {
        x = y = val;
    }

    Vector2D(double xVal, double yVal)
    {
        x = xVal;
        y = yVal;
    }

    // Method Overloading
    void setValues(double val)
    {
        x = y = val;
    }

    void setValues(double xVal, double yVal)
    {
        x = xVal;
        y = yVal;
    }

    void print() const
    {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }

    /*
    ========================================
        OPERATOR OVERLOADING
    ========================================
    */

    // + Operator
    Vector2D operator+(const Vector2D &other) const
    {
        return Vector2D(x + other.x, y + other.y);
    }

    // - Operator
    Vector2D operator-(const Vector2D &other) const
    {
        return Vector2D(x - other.x, y - other.y);
    }

    // * Operator (scalar multiplication)
    Vector2D operator*(double scalar) const
    {
        return Vector2D(x * scalar, y * scalar);
    }

    // == Operator
    bool operator==(const Vector2D &other) const
    {
        return (x == other.x && y == other.y);
    }

    // != Operator
    bool operator!=(const Vector2D &other) const
    {
        return !(*this == other);
    }

    // Prefix ++
    Vector2D &operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    // Postfix ++
    Vector2D operator++(int)
    {
        Vector2D temp = *this;
        x++;
        y++;
        return temp;
    }

    // [] Operator (for fun practice)
    double operator[](int index) const
    {
        if (index == 0)
            return x;
        else if (index == 1)
            return y;
        else
            throw out_of_range("Index out of range");
    }

    // Friend for << (cout)
    friend ostream &operator<<(ostream &out, const Vector2D &v)
    {
        out << "Vector(" << v.x << ", " << v.y << ")";
        return out;
    }

    // Friend for >> (cin)
    friend istream &operator>>(istream &in, Vector2D &v)
    {
        cout << "Enter x and y: ";
        in >> v.x >> v.y;
        return in;
    }
};

/*
========================================
        MAIN (TEST EVERYTHING)
========================================
*/

int main()
{
    cout << "===== Function Overloading =====" << endl;
    cout << add(2, 3) << endl;
    cout << add(2.5, 3.5) << endl;
    cout << add(1, 2, 3) << endl;

    cout << "\n===== Constructor Overloading =====" << endl;
    Vector2D v1;
    Vector2D v2(5);
    Vector2D v3(3, 4);

    v1.print();
    v2.print();
    v3.print();

    cout << "\n===== Method Overloading =====" << endl;
    v1.setValues(10);
    v1.print();

    v1.setValues(7, 8);
    v1.print();

    cout << "\n===== Operator Overloading =====" << endl;

    Vector2D a(2, 3), b(1, 4);

    Vector2D sum = a + b;
    Vector2D diff = a - b;
    Vector2D scaled = a * 2;

    cout << "a + b = " << sum << endl;
    cout << "a - b = " << diff << endl;
    cout << "a * 2 = " << scaled << endl;

    cout << "\nComparison:" << endl;
    cout << (a == b ? "Equal" : "Not Equal") << endl;

    cout << "\nIncrement:" << endl;
    ++a;
    cout << "After prefix ++: " << a << endl;

    a++;
    cout << "After postfix ++: " << a << endl;

    cout << "\nIndex Operator:" << endl;
    cout << "a[0] = " << a[0] << endl;
    cout << "a[1] = " << a[1] << endl;

    cout << "\nInput Operator:" << endl;
    Vector2D userVec;
    cin >> userVec;
    cout << "You entered: " << userVec << endl;

    return 0;
}