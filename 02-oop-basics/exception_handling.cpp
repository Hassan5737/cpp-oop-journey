#include <iostream>
#include <string>
using namespace std;

// =========================
// Function: Division
// =========================
double divide(double a, double b)
{
    if (b == 0)
        throw "Error: Division by zero!";

    return a / b;
}

// =========================
// Function: Age Check
// =========================
void checkAge(int age)
{
    if (age < 0)
        throw invalid_argument("Age cannot be negative!");

    if (age < 18)
        throw "You are too young!";

    cout << "Access granted!" << endl;
}

// =========================
// Function: Array Access
// =========================
int getElement(int arr[], int size, int index)
{
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range!");

    return arr[index];
}

// =========================
// MAIN
// =========================
int main()
{
    // =========================
    // Example 1: Division
    // =========================
    try
    {
        cout << "Division result: " << divide(10, 0) << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    cout << "----------------------" << endl;

    // =========================
    // Example 2: Age Check
    // =========================
    try
    {
        checkAge(15);
    }
    catch (const invalid_argument& e)
    {
        cout << "Invalid Argument: " << e.what() << endl;
    }
    catch (const char* msg)
    {
        cout << msg << endl;
    }

    cout << "----------------------" << endl;

    // =========================
    // Example 3: Array Access
    // =========================
    int arr[3] = {1, 2, 3};

    try
    {
        cout << getElement(arr, 3, 5) << endl;
    }
    catch (const out_of_range& e)
    {
        cout << "Out of Range: " << e.what() << endl;
    }

    cout << "----------------------" << endl;

    // =========================
    // Example 4: Catch All
    // =========================
    try
    {
        throw 404; 
    }
    catch (...)
    {
        cout << "Unknown error occurred!" << endl;
    }

    return 0;
}