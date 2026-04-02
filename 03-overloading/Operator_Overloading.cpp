#include <iostream>
using namespace std;

class Vector2D
{
private:
    double x, y;

public:
  
    Vector2D(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }

    
    Vector2D operator+(const Vector2D& other)
    {
        return Vector2D(x + other.x, y + other.y);
    }


    Vector2D operator-(const Vector2D& other)
    {
        return Vector2D(x - other.x, y - other.y);
    }


    Vector2D operator*(double scalar)
    {
        return Vector2D(x * scalar, y * scalar);
    }

    
    bool operator==(const Vector2D& other)
    {
        return (x == other.x && y == other.y);
    }

    // Friend for printing 
    friend ostream& operator<<(ostream& out, const Vector2D& v);
};

// Overloading << (outside class)
ostream& operator<<(ostream& out, const Vector2D& v)
{
    out << "(" << v.x << ", " << v.y << ")";
    return out;
}

int main()
{
    Vector2D v1(2, 3);
    Vector2D v2(1, 4);

    Vector2D v3 = v1 + v2;
    Vector2D v4 = v1 - v2;
    Vector2D v5 = v1 * 3;

    cout << "v1 + v2 = " << v3 << endl;
    cout << "v1 - v2 = " << v4 << endl;
    cout << "v1 * 3 = " << v5 << endl;

    if (v1 == v2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    return 0;
}