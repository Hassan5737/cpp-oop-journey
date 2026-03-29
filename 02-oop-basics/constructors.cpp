#include <iostream>
#include <string>
using namespace std;

/*
    Constructors 
    Covers:
    - Default Constructor
    - Parameterized Constructor
    - Copy Constructor
    - Constructor Overloading
*/

class Car {
private:
    string name;
    int speed;

public:

    // ==========================
    // Default Constructor
    // ==========================
    Car() {
        name = "Unknown";
        speed = 0;
        cout << "Default Constructor Called\n";
    }

    // ==========================
    // Parameterized Constructor
    // ==========================
    Car(string n, int s) {
        name = n;
        speed = s;
        cout << "Parameterized Constructor Called\n";
    }

    // ==========================
    // Copy Constructor
    // ==========================
    Car(const Car& other) {
        name = other.name;
        speed = other.speed;
        cout << "Copy Constructor Called\n";
    }

    // ==========================
    // Print
    // ==========================
    void print() const {
        cout << "Name: " << name << endl;
        cout << "Speed: " << speed << endl;
    }
};

// ==========================
// MAIN
// ==========================
int main() {

    cout << "=== Constructors Demo ===\n\n";

    // Default
    Car c1;
    c1.print();

    cout << "\n";

    // Parameterized
    Car c2("BMW", 300);
    c2.print();

    cout << "\n";

    // Copy
    Car c3 = c2;
    c3.print();

    return 0;
}