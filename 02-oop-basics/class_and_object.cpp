#include <iostream>
#include <string>
using namespace std;

/*
    Class & Object 
    Concepts:
    - Encapsulation
    - Data hiding
    - Clean interface
*/

// ==========================
// Car Class
// ==========================
class Car {
private:
    string name;
    string color;
    int maxSpeed;
    int model;

public:

    // Setter methods (with validation)
    void setName(string n) {
        if (n.empty()) {
            cout << "Invalid name\n";
            return;
        }
        name = n;
    }

    void setColor(string c) {
        color = c;
    }

    void setMaxSpeed(int speed) {
        if (speed <= 0) {
            cout << "Invalid speed\n";
            return;
        }
        maxSpeed = speed;
    }

    void setModel(int m) {
        if (m < 1900) {
            cout << "Invalid model\n";
            return;
        }
        model = m;
    }

    // Getter methods
    string getName() const {
        return name;
    }

    string getColor() const {
        return color;
    }

    int getMaxSpeed() const {
        return maxSpeed;
    }

    int getModel() const {
        return model;
    }

    // Behavior
    void print() const {
        cout << "Car Info:\n";
        cout << "Name: " << name << endl;
        cout << "Color: " << color << endl;
        cout << "Max Speed: " << maxSpeed << endl;
        cout << "Model: " << model << endl;
    }
};

// ==========================
// Triangle Class
// ==========================
class Triangle {
private:
    double base;
    double height;

public:

    void setDimensions(double b, double h) {
        if (b <= 0 || h <= 0) {
            cout << "Invalid dimensions\n";
            return;
        }
        base = b;
        height = h;
    }

    double area() const {
        return 0.5 * base * height;
    }

    void print() const {
        cout << "Triangle Info:\n";
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << area() << endl;
    }
};

// ==========================
// MAIN
// ==========================
int main() {

    cout << "=== Class & Object Demo ===\n\n";

    // Car Object
    Car car1;
    car1.setName("BMW");
    car1.setColor("Black");
    car1.setMaxSpeed(280);
    car1.setModel(2022);

    car1.print();

    cout << "\n";

    // Triangle Object
    Triangle t1;
    t1.setDimensions(5, 10);
    t1.print();

    return 0;
}