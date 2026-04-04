#include <iostream>
using namespace std;

class Vector2D
{
private:
    float x, y;

public:
   
    Vector2D(float a = 0, float b = 0)
    {
        x = a;
        y = b;
    }

   
    void print() const
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }

    //  Binary Operator Overloading (+)
    Vector2D operator+(const Vector2D& other)
    {
        return Vector2D(x + other.x, y + other.y);
    }

    //  Unary Operator Overloading (-)
    Vector2D operator-()
    {
        return Vector2D(-x, -y);
    }

    //  Operator +=
    Vector2D& operator+=(const Vector2D& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
};

int main()
{
    Vector2D v1(3, 4);
    Vector2D v2(1, 2);

    
    Vector2D v3 = v1 + v2;


    Vector2D v4 = -v1;

    
    v1 += v2;

    cout << "v1: ";
    v1.print();

    cout << "v2: ";
    v2.print();

    cout << "v3 (v1 + v2): ";
    v3.print();

    cout << "v4 (-v1): ";
    v4.print();

    return 0;
}