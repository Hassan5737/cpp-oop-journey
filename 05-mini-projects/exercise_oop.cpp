#include <iostream>
using namespace std;

/*
====================================================
                OOP Exercise
====================================================

Write a complete OOP program to represent a Car.

Requirements:

1. Create a class called Car.

2. The class should contain data members such as:
   - carName
   - model
   - price

3. Use a Constructor to initialize all data members.

4. Create a member function outside the class
   to display the car price.

5. Create a Friend Function that increases
   the car price by 1000.

   ====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Access Specifiers
- Member Functions
- Function Definition Outside Class
- Friend Function
- Encapsulation

====================================================
*/

class Car
{
    private:
        string name;
        int model;
        int price;
    public:
        Car(string n, int m, int p)
        {
            name = n;
            model = m;
            price = p;
        }

        void show ();
        friend void add (Car &ob);
};

void Car::show ()
{
    cout << "car price is: " << price;
}

void add (Car &ob)
{
    cout << "The old car's price is: " << ob.price << endl;
    ob.price += 1000;
    cout << "The new car's price is: " << ob.price << endl;
}

int main ()
{
    Car ob1("BMW", 2017 , 100000);
    ob1.show();
    add(ob1);
    return 0;
}