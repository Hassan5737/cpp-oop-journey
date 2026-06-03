#include <iostream>
using namespace std;

/*
====================================================
            first    OOP Exercise
====================================================

Write a complete program to represent
a class called Sum.

====================================================
Requirements:
====================================================

1. Create a class called Sum.

2. Define one data member:
   - x

3. Create two objects:
   - ob1
   - ob2

4. Add the two objects using:
   ob1 + ob2

5. Implement the solution using
   Operator Overloading.

6. Solve the problem using
   three different methods.

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Operator Overloading
- Member Function
- Friend Function
- Returning Objects

====================================================
*/

class sum
{
    private:
        int x = 0;
    public:
      sum ()
      {
         cout << "Enter x : " << endl;
         cin >> x;
      }
        void setval()
        {
            cout << "Enter x : " << endl;
            cin >> x;
        }
// ====================================================
//                     method 1:
// ====================================================
        void plus(sum ob1, sum ob2)
        {
         cout << ob1.x + ob2.x << endl;
        }
// ====================================================
//                     method 2:
// ====================================================
         void add(sum ob1)
         {
            cout << x + ob1.x << endl;
         }
// ====================================================
//                     method 3:
// ====================================================
         void operator +(ob1)
         {
            cout << x + bo1.x << endl;
         }
};


int main()
{
   sum ob1;
   sum ob2;

    return 0;
}