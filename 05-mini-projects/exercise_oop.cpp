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

/*
====================================================
              second  OOP Exercise
====================================================

Write a complete OOP program to represent 3 workers.

Requirements:

1. Create a class called Worker.

2. The class should contain:
   - workerName
   - salary

3. Use a Constructor to initialize
   the worker name and salary.

4. Create 3 objects for 3 different workers.

5. Create a Friend Function to calculate
   the average salary for all workers.

6. Print:
   - each worker information
   - average salary

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Friend Function
- Encapsulation
- Passing Objects to Functions
- Accessing Private Members using Friend Function

====================================================
*/

int main ()
{
    Car ob1("BMW", 2017 , 100000);
    ob1.show();
    add(ob1);
    return 0;
}

