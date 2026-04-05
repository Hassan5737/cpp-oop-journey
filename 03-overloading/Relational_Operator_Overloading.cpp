#include <iostream>
using namespace std;

// Class Relational: Demonstrates relational operator overloading

class Relational {
private:
    int x, y, z;

public:
    // Constructors
    Relational(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

    // Overload == operator
    bool operator==(const Relational &r) {
        return (x == r.x && y == r.y && z == r.z);
    }

    // Overload != operator
    bool operator!=(const Relational &r) {
        return !(*this == r);
    }

    // Optional: Overload < operator (compare sum of attributes)
    bool operator<(const Relational &r) {
        return (x + y + z) < (r.x + r.y + r.z);
    }

    // Optional: Overload > operator (compare sum of attributes)
    bool operator>(const Relational &r) {
        return (x + y + z) > (r.x + r.y + r.z);
    }
};

int main() {
    Relational a(10, 20, 30), b(10, 20, 30), c(5, 10, 15);

    if (a == b)
        cout << "a and b are equal" << endl;
    else
        cout << "a and b are not equal" << endl;

    if (a != c)
        cout << "a and c are not equal" << endl;
    else
        cout << "a and c are equal" << endl;

    if (c < a)
        cout << "c is less than a" << endl;

    if (a > c)
        cout << "a is greater than c" << endl;

    return 0;
}