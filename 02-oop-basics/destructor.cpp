#include <iostream>
#include <cstring>
using namespace std;

class SmartBuffer {
private:
    int* data;
    size_t size;

public:
    // =========================
    // Default Constructor
    // =========================
    SmartBuffer() : data(nullptr), size(0) {
        cout << "Default Constructor\n";
    }

    // =========================
    // Parameterized Constructor
    // =========================
    SmartBuffer(size_t s) : size(s) {
        data = new int[size];
        for (size_t i = 0; i < size; i++) {
            data[i] = 0;
        }
        cout << "Parameterized Constructor (" << size << " elements)\n";
    }

    // =========================
    // Copy Constructor (Deep Copy)
    // =========================
    SmartBuffer(const SmartBuffer& other) {
        size = other.size;

        if (other.data) {
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }

        cout << "Copy Constructor (Deep Copy)\n";
    }

    // =========================
    // Copy Assignment Operator
    // =========================
    SmartBuffer& operator=(const SmartBuffer& other) {
        if (this == &other) return *this; // self assignment check

        delete[] data; // clean old memory

        size = other.size;

        if (other.data) {
            data = new int[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        } else {
            data = nullptr;
        }

        cout << "Copy Assignment Operator\n";
        return *this;
    }

    // =========================
    // Move Constructor
    // =========================
    SmartBuffer(SmartBuffer&& other) noexcept {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        cout << "Move Constructor\n";
    }

    // =========================
    // Move Assignment Operator
    // =========================
    SmartBuffer& operator=(SmartBuffer&& other) noexcept {
        if (this == &other) return *this;

        delete[] data;

        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        cout << "Move Assignment Operator\n";
        return *this;
    }

    // =========================
    // Destructor
    // =========================
    ~SmartBuffer() {
        delete[] data;
        cout << "Destructor: Memory Released\n";
    }

    // =========================
    // Utilities
    // =========================
    void set(size_t index, int value) {
        if (index < size) {
            data[index] = value;
        }
    }

    int get(size_t index) const {
        if (index < size) {
            return data[index];
        }
        return -1;
    }

    void print() const {
        for (size_t i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    size_t getSize() const {
        return size;
    }
};

// =========================
// Function to test Move
// =========================
SmartBuffer createBuffer() {
    SmartBuffer temp(5);
    for (int i = 0; i < 5; i++) {
        temp.set(i, i * 10);
    }
    return temp; // Move happens here
}

int main() {

    cout << "\n--- Create arr1 ---\n";
    SmartBuffer arr1(5);
    for (int i = 0; i < 5; i++) {
        arr1.set(i, i + 1);
    }

    cout << "arr1: ";
    arr1.print();

    cout << "\n--- Copy Constructor ---\n";
    SmartBuffer arr2 = arr1;
    cout << "arr2: ";
    arr2.print();

    cout << "\n--- Copy Assignment ---\n";
    SmartBuffer arr3;
    arr3 = arr1;
    cout << "arr3: ";
    arr3.print();

    cout << "\n--- Move Constructor ---\n";
    SmartBuffer arr4 = createBuffer();
    cout << "arr4: ";
    arr4.print();

    cout << "\n--- Move Assignment ---\n";
    SmartBuffer arr5;
    arr5 = createBuffer();
    cout << "arr5: ";
    arr5.print();

    cout << "\n--- End of Program ---\n";

    return 0;
}