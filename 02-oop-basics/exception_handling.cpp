#include <iostream>
#include <string>
#include <exception>
using namespace std;

// =========================
// Custom Exception Base Class
// =========================
class AppException : public exception
{
protected:
    string message;

public:
    AppException(const string& msg) : message(msg) {}

    virtual const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// =========================
// Derived Exceptions
// =========================
class DivisionByZeroException : public AppException
{
public:
    DivisionByZeroException() : AppException("Division by zero is not allowed") {}
};

class InvalidAgeException : public AppException
{
public:
    InvalidAgeException() : AppException("Age cannot be negative") {}
};

class UnderAgeException : public AppException
{
public:
    UnderAgeException() : AppException("User is under age") {}
};

class OutOfRangeException : public AppException
{
public:
    OutOfRangeException() : AppException("Index out of range") {}
};

class InsufficientBalanceException : public AppException
{
public:
    InsufficientBalanceException() : AppException("Insufficient balance") {}
};

class NegativeAmountException : public AppException
{
public:
    NegativeAmountException() : AppException("Negative amount is not allowed") {}
};

// =========================
// Division Function
// =========================
double divide(double a, double b)
{
    if (b == 0)
        throw DivisionByZeroException();

    return a / b;
}

// =========================
// Age Check
// =========================
void checkAge(int age)
{
    if (age < 0)
        throw InvalidAgeException();

    if (age < 18)
        throw UnderAgeException();

    cout << "Access granted" << endl;
}

// =========================
// Array Access
// =========================
int getElement(int arr[], int size, int index)
{
    if (index < 0 || index >= size)
        throw OutOfRangeException();

    return arr[index];
}

// =========================
// Bank System
// =========================
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b) : balance(b) {}

    void withdraw(double amount)
    {
        if (amount < 0)
            throw NegativeAmountException();

        if (amount > balance)
            throw InsufficientBalanceException();

        balance -= amount;
    }

    double getBalance() const
    {
        return balance;
    }
};


int main()
{
    // Division
    try
    {
        cout << divide(10, 0) << endl;
    }
    catch (const DivisionByZeroException& e)
    {
        cout << e.what() << endl;
    }

    cout << "------------------" << endl;

    // Age Check
    try
    {
        checkAge(15);
    }
    catch (const AppException& e)
    {
        cout << e.what() << endl;
    }

    cout << "------------------" << endl;

    // Array Access
    int arr[3] = {1, 2, 3};

    try
    {
        cout << getElement(arr, 3, 5) << endl;
    }
    catch (const OutOfRangeException& e)
    {
        cout << e.what() << endl;
    }

    cout << "------------------" << endl;

    // Bank System
    BankAccount acc(100);

    try
    {
        acc.withdraw(150);
    }
    catch (const NegativeAmountException& e)
    {
        cout << e.what() << endl;
    }
    catch (const InsufficientBalanceException& e)
    {
        cout << e.what() << endl;
    }

    cout << "------------------" << endl;

    // Multiple Catch Types
    try
    {
        throw 404;
    }
    catch (int e)
    {
        cout << "Integer exception: " << e << endl;
    }
    catch (...)
    {
        cout << "Unknown exception" << endl;
    }

    return 0;
}