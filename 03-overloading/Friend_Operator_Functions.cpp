#include <iostream>
using namespace std;

class Vector3 {
private:
    int x, y, z;

public:
    // Constructor
    Vector3(int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}

    // Member operator +
    Vector3 operator+(const Vector3& v) const {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    // Member operator ==
    bool operator==(const Vector3& v) const {
        return (x == v.x && y == v.y && z == v.z);
    }

    // Member operator -
    Vector3 operator-(const Vector3& v) const {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    // Friend operator <<
    friend ostream& operator<<(ostream& out, const Vector3& v);

    // Friend relational operator >
    friend bool operator>(const Vector3& a, const Vector3& b);

    // Friend relational operator <
    friend bool operator<(const Vector3& a, const Vector3& b);

    // Friend scalar multiplication
    friend Vector3 operator*(const Vector3& v, int scalar);

    // Friend symmetric scalar multiplication
    friend Vector3 operator*(int scalar, const Vector3& v);
};

// Output operator
ostream& operator<<(ostream& out, const Vector3& v) {
    out << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return out;
}

// Relational operator >
bool operator>(const Vector3& a, const Vector3& b) {
    return (a.x + a.y + a.z) > (b.x + b.y + b.z);
}

// Relational operator <
bool operator<(const Vector3& a, const Vector3& b) {
    return (a.x + a.y + a.z) < (b.x + b.y + b.z);
}

// Scalar multiplication (Vector * int)
Vector3 operator*(const Vector3& v, int scalar) {
    return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

// Scalar multiplication (int * Vector)
Vector3 operator*(int scalar, const Vector3& v) {
    return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

// Main function
int main() {
    Vector3 v1(1, 2, 3);
    Vector3 v2(4, 5, 6);

    Vector3 v3 = v1 + v2;
    cout << "v1 + v2 = " << v3 << endl;

    Vector3 v4 = v2 - v1;
    cout << "v2 - v1 = " << v4 << endl;

    if (v1 == v2)
        cout << "v1 == v2" << endl;
    else
        cout << "v1 != v2" << endl;

    if (v2 > v1)
        cout << "v2 is greater than v1" << endl;

    if (v1 < v2)
        cout << "v1 is less than v2" << endl;

    Vector3 v5 = v1 * 3;
    cout << "v1 * 3 = " << v5 << endl;

    Vector3 v6 = 2 * v2;
    cout << "2 * v2 = " << v6 << endl;

    return 0;
}