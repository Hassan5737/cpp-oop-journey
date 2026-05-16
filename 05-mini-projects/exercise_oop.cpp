#include <iostream>
using namespace std;

/*
====================================================
                OOP Exercise in C++
====================================================

Requirements:

Create a class called Student.

The class should contain:

Private:
- name
- id
- gpa

Public:
- Default Constructor
- Parameterized Constructor
- Setter Functions
- Getter Functions
- displayInfo() function
- isExcellent() function

====================================================
Tasks in main():
====================================================

1. Create an object using the Default Constructor.
2. Set the values using Setter Functions.
3. Print the student information.
4. Check if the student is excellent.
5. Create another object using the Parameterized Constructor.
6. Print the second student information.

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Encapsulation
- Constructors
- Default Constructor
- Parameterized Constructor
- Setter & Getter
- Member Functions
- Boolean Functions

====================================================
*/

class Student
{
private:
    string name;
    int id;
    double gpa;

public:

    // Default Constructor
    Student()
    {
        name = "Unknown";
        id = 0;
        gpa = 0.0;
    }

    // Parameterized Constructor
    Student(string n, int i, double g)
    {
        name = n;
        id = i;
        gpa = g;
    }

    // Setter Functions
    void setName(string n)
    {
        name = n;
    }

    void setId(int i)
    {
        id = i;
    }

    void setGpa(double g)
    {
        gpa = g;
    }

    // Getter Functions
    string getName()
    {
        return name;
    }

    int getId()
    {
        return id;
    }

    double getGpa()
    {
        return gpa;
    }

    // Display Function
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "GPA: " << gpa << endl;
    }

    // Check if student is excellent
    bool isExcellent()
    {
        return gpa >= 3.5;
    }
};

int main()
{
    // Object using Default Constructor
    Student s1;

    s1.setName("Hasan");
    s1.setId(101);
    s1.setGpa(3.8);

    cout << "First Student:" << endl;
    s1.displayInfo();

    if (s1.isExcellent())
    {
        cout << "Excellent Student" << endl;
    }
    else
    {
        cout << "Not Excellent" << endl;
    }

    cout << "--------------------------" << endl;

    // Object using Parameterized Constructor
    Student s2("Ali", 202, 2.9);

    cout << "Second Student:" << endl;
    s2.displayInfo();

    if (s2.isExcellent())
    {
        cout << "Excellent Student" << endl;
    }
    else
    {
        cout << "Not Excellent" << endl;
    }

    return 0;
}



/*
====================================================
                Second OOP Exercise
====================================================

Requirements:

Create a class called BankAccount.

The class should contain:

Private:
- ownerName
- accountNumber
- balance

Public:
- Default Constructor
- Parameterized Constructor
- deposit() function
- withdraw() function
- displayAccountInfo() function
- Getter Functions

====================================================
Tasks:
====================================================

1. Create an account using the Default Constructor.
2. Set values using the constructor or functions.
3. Deposit money into the account.
4. Withdraw money from the account.
5. Print account information.
6. Prevent withdrawing more than the balance.

====================================================
Expected OOP Concepts:
====================================================

- Classes & Objects
- Encapsulation
- Constructors
- Functions
- Data Hiding
- Validation

====================================================
Solution:
====================================================
*/

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance;

public:

    // Default Constructor
    BankAccount()
    {
        ownerName = "Unknown";
        accountNumber = 0;
        balance = 0.0;
    }

    // Parameterized Constructor
    BankAccount(string name, int number, double money)
    {
        ownerName = name;
        accountNumber = number;
        balance = money;
    }

    // Deposit Function
    void deposit(double amount)
    {
        balance += amount;
    }

    // Withdraw Function
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal Successful" << endl;
        }
        else
        {
            cout << "Insufficient Balance" << endl;
        }
    }

    // Display Function
    void displayAccountInfo()
    {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Getter Functions
    string getOwnerName()
    {
        return ownerName;
    }

    int getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }
};

int main2()
{
    BankAccount acc1("Hasan", 12345, 5000);

    acc1.deposit(2000);
    acc1.withdraw(1500);
    acc1.withdraw(10000);

    cout << "--------------------------" << endl;

    acc1.displayAccountInfo();

    return 0;
}
