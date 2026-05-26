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

class Worker
{
   private:
      string name;
      double salary;
   public:
   Worker(string n, double s)
   {
      name = n;
      salary = s;
   }
  friend void average (Worker &ob1, Worker &ob2, Worker &ob3);

  void show()
{
    cout << name << " : " << salary << endl;
}

};

 void average (Worker &ob1, Worker &ob2, Worker &ob3);
{
   double avg =0;
   avg = (ob1.salary + ob2.salary + ob3.salary ) /3;
   cout << "The average is: " << avg << endl;
}


/*
====================================================
              Third OOP Exercise
====================================================

Write a complete OOP program to represent:

1. A Teacher class
2. An Engineer class

====================================================
Requirements:
====================================================

Teacher Class:
- Define two data members
  Example:
  - teacherName
  - salary

Engineer Class:
- Define two data members
  Example:
  - engineerName
  - salary

====================================================
Program Tasks:
====================================================

1. Use Constructors to initialize all data members.

2. Create:
   - a Teacher object named Ali
   - an Engineer object named Ahmed

3. Create a Friend Function that:
   - accesses both salaries
   - adds 1000 to each salary

4. Print:
   - old salaries
   - new salaries after increasing

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Multiple Classes
- Friend Function
- Accessing Private Members
- Encapsulation

====================================================
*/

class Engineer;

// ==============================
// Teacher Class
// ==============================
class Teacher
{
private:
    string teacherName;
    int salary;

public:

    // Constructor
    Teacher(string n, int s)
    {
        this->teacherName = n;
        this->salary = s;
    }

    // Friend Function
    friend void add(Teacher &ob1, Engineer &ob2);
};

// ==============================
// Engineer Class
// ==============================
class Engineer
{
private:
    string engineerName;
    int salary;

public:

    // Constructor
    Engineer(string n, int s)
    {
        this->engineerName = n;
        this->salary = s;
    }

    // Friend Function
    friend void add(Teacher &ob1, Engineer &ob2);
};

// ==============================
// Friend Function
// ==============================
void add(Teacher &ob1, Engineer &ob2)
{
    cout << "Old Teacher Salary: "
         << ob1.salary << endl;

    cout << "Old Engineer Salary: "
         << ob2.salary << endl;

    // Increase salaries
    ob1.salary += 1000;
    ob2.salary += 1000;

    cout << "----------------------" << endl;

    cout << "New Teacher Salary: "
         << ob1.salary << endl;

    cout << "New Engineer Salary: "
         << ob2.salary << endl;
}


int main ()
{

   //  Car ob1("BMW", 2017 , 100000);
   //  ob1.show();
   //  add(ob1);

   // Worker o1("Hassan" , 40000);
   // Worker o2("Ahmed" , 30000);
   // Worker o3("Assad" , 20000);
   // average(o1, o2, o3);

    Teacher t1("Ali", 5000);
    Engineer e1("Ahmed", 7000);
    add(t1, e1);


    return 0;
}

