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


/*
====================================================
             fourth OOP Exercise
====================================================

Write a complete program to represent
a Rectangle class.

====================================================
Requirements:
====================================================

1. Create a class called Rectangle.

2. Define two data members:
   - length
   - width

3. Use Constructor Overloading:
   - Default Constructor
   - Parameterized Constructor

4. Create a member function outside the class
   to print rectangle information.

5. Create 2 Rectangle objects.

6. Create a Friend Function to:
   - calculate area for each rectangle
   - find the biggest rectangle area

7. Print:
   - rectangle dimensions
   - each area
   - biggest area

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructor Overloading
- Member Functions
- Function Definition Outside Class
- Friend Function
- Encapsulation
- Passing Objects to Functions

====================================================
*/

class Rectangle
{
private:
    int length;
    int width;

public:

    // Default Constructor
    Rectangle()
    {
        cout << "Enter Length: ";
        cin >> length;

        cout << "Enter Width: ";
        cin >> width;
    }

    // Parameterized Constructor
    Rectangle(int l, int w)
    {
        length = l;
        width = w;
    }

    void print();

    friend void calc(Rectangle r1, Rectangle r2);
};

// Function Definition Outside Class
void Rectangle::print()
{
    cout << "Length = " << length << endl;
    cout << "Width  = " << width << endl;
}

// Friend Function
void calc(Rectangle r1, Rectangle r2)
{
    int area1 = r1.length * r1.width;
    int area2 = r2.length * r2.width;

    cout << "\nArea of Rectangle 1 = "
         << area1 << endl;

    cout << "Area of Rectangle 2 = "
         << area2 << endl;

    cout << "\nBiggest Area = ";

    if (area1 > area2)
    {
        cout << area1 << endl;
    }
    else if (area2 > area1)
    {
        cout << area2 << endl;
    }
    else
    {
        cout << "Both Areas Are Equal" << endl;
    }
}

/*
====================================================
              fifth  OOP Exercise
====================================================

Write a complete program to represent
a Student class.

====================================================
Requirements:
====================================================

1. Create a class called Student.

2. Define four data members:
   - name
   - age
   - grade
   - id

3. Use a Parameterized Constructor
   to initialize all data members.

4. Create another class called University.

5. Create a member function inside
   the University class.

6. Use the member function of the
   University class to print all
   Student information.

7. Create:
   - one Student object
   - one University object

8. Display:
   - Student Name
   - Student Age
   - Student Grade
   - Student ID

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Constructors
- Multiple Classes
- Member Functions
- Friend Class
- Encapsulation
- Accessing Private Members

====================================================
*/

class Stu
{
   private:
      string name;
      int age;
      int grade;
      int id;
   public:
      Stu(string n, int a, int g, int id)
      {
         this->name = n;
         this->age = a;
         this->grade = g;
         this->id = id;
      }
      friend class University;
};

class University : public Stu;
{
   public:
      void print(Stu ob)
      {
         cout << "your name is: " << ob.name << endl;
         cout << "your age is: " << ob.age << endl;
         cout << "your grade is: " << ob.grade << endl;
         cout << "your id is: " << ob.id << endl;
      }

};



int main ()
{

   //  Car ob1("BMW", 2017 , 100000);
   //  ob1.show();
   //  add(ob1);

   // Worker o1("Hassan" , 40000);
   // Worker o2("Ahmed" , 30000);
   // Worker o3("Assad" , 20000);
   // average(o1, o2, o3);

   //  Teacher t1("Ali", 5000);
   //  Engineer e1("Ahmed", 7000);
   //  add(t1, e1);

   //  Rectangle r1;

   //  Rectangle r2(10, 20);

   //  cout << "\nRectangle 1:\n";
   //  r1.print();

   //  cout << "\nRectangle 2:\n";
   //  r2.print();

   //  calc(r1, r2);

   Stu s (12,100,1234,"Hassan");
   University u;
   u.print(s);
    return 0;
}