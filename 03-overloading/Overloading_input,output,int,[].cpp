#include <iostream>
using namespace std;

class Array3 {
private:
    int arr[3];

public:
    
    Array3(int a = 0, int b = 0, int c = 0) {
        arr[0] = a;
        arr[1] = b;
        arr[2] = c;
    }

   
    int& operator[](int index) {
        return arr[index];
    }

    const int& operator[](int index) const {
        return arr[index];
    }

    operator int() const {
        return arr[0] + arr[1] + arr[2];
    }
    
    friend ostream& operator<<(ostream& out, const Array3& a);

    friend istream& operator>>(istream& in, Array3& a);
};
ostream& operator<<(ostream& out, const Array3& a) {
    out << "[" << a.arr[0] << ", " << a.arr[1] << ", " << a.arr[2] << "]";
    return out;
}
istream& operator>>(istream& in, Array3& a) {
    in >> a.arr[0] >> a.arr[1] >> a.arr[2];
    return in;
}



int main() {
    Array3 a;

    cout << "Enter 3 numbers: ";
    cin >> a;

    cout << "Array: " << a << endl;

    
    a[0] = 100;
    cout << "After modification: " << a << endl;

    
    int sum = a;
    cout << "Sum = " << sum << endl;

    return 0;
}