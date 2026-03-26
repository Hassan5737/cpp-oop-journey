#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

/*
     Functions Review
    - Clean structure
    - Better naming
    - Edge cases awareness
*/

// ==========================
// Basic Operations
// ==========================

int sum(int a, int b) {
    return a + b;
}

double average(double a, double b, double c) {
    return (a + b + c) / 3.0;
}

// ==========================
// Logical Functions
// ==========================

int maxOfThree(int a, int b, int c) {
    int result = a;

    if (b > result) result = b;
    if (c > result) result = c;

    return result;
}

int minOfThree(int a, int b, int c) {
    int result = a;

    if (b < result) result = b;
    if (c < result) result = c;

    return result;
}

// ==========================
// Void Function
// ==========================

void printLine(string msg) {
    cout << msg << endl;
}

// ==========================
// Default Arguments
// ==========================

int power(int base, int exponent = 2) {
    int result = 1;

    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}

// ==========================
// Pass by Reference
// ==========================

void increment(int &x) {
    x++;
}

void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// ==========================
// Utility Functions
// ==========================

bool isEven(int n) {
    return n % 2 == 0;
}

int factorial(int n) {
    if (n < 0) return -1; // edge case

    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

// ==========================
// Built-in usage wrapper
// ==========================

void builtInDemo() {
    cout << "abs(-5): " << abs(-5) << endl;
    cout << "sqrt(16): " << sqrt(16) << endl;
    cout << "max(10, 20): " << max(10, 20) << endl;
}

// ==========================
// MAIN
// ==========================

int main() {

    printLine("=== Functions Review ===");

    cout << "Sum: " << sum(10, 20) << endl;
    cout << "Average: " << average(10, 20, 30) << endl;

    cout << "Max: " << maxOfThree(5, 9, 3) << endl;
    cout << "Min: " << minOfThree(5, 9, 3) << endl;

    cout << "Power(5): " << power(5) << endl;
    cout << "Power(2, 4): " << power(2, 4) << endl;

    int x = 10;
    increment(x);
    cout << "After increment: " << x << endl;

    int a = 3, b = 7;
    swapValues(a, b);
    cout << "After swap -> a: " << a << ", b: " << b << endl;

    cout << "Is 10 even? " << isEven(10) << endl;
    cout << "Factorial 5: " << factorial(5) << endl;

    builtInDemo();

    return 0;
}