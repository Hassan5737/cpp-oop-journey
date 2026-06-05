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
         void operator +(sum ob1)
         {
            cout << x + ob1.x << endl;
         }
};

/*
====================================================
              second  OOP Exercise
====================================================

Write a complete program to represent
a class called Cal.

====================================================
Requirements:
====================================================

1. Create a class called Cal.

2. Create two objects:
   - ob1
   - ob2

3. Define two data members:
   - x
   - y

4. Store x in object ob1.

5. Store y in object ob2.

6. Subtract the value of y
   from the value of x.

7. Display the result.

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Multiple Objects
- Data Members
- Member Functions
- Arithmetic Operations

====================================================
*/



class Cal 
{
   private:
      int x = 0;
      int y = 0;
   public:
      Cal()
      {
         cout << "enter x: " << endl;
         cin >> x;
         cout << "enter y: " << endl;
         cin >> y;
      }

      void operator - (Cal ob)
      {
         cout << x - ob.y << endl;
      }
};

/*
====================================================
              third  OOP Exercise
====================================================

Write a complete program to represent
a class called Multiply.

====================================================
Requirements:
====================================================

1. Create a class called Multiply.

2. Create two objects:
   - ob1
   - ob2

3. Define two data members:
   - x
   - y

4. Store x in object ob1.

5. Store y in object ob2.

6. Multiply the value of x
   by the value of y.

7. Display the result.

8. Implement the solution using
   Operator Overloading.

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Operator Overloading
- Multiple Objects
- Data Members
- Arithmetic Operations

====================================================
*/


int main()
{
   // Cal ob1;
   // Cal ob2;
    return 0;
}