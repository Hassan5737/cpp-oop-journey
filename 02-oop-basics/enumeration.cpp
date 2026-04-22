#include <iostream>
#include <string>
using namespace std;#include <iostream>
#include <string>
using namespace std;

// =========================
// Basic enum
// =========================
enum Color
{
    Red,
    Green,
    Blue
};

// =========================
// Enum class (recommended)
// =========================
enum class Status
{
    Pending,
    Shipped,
    Delivered,
    Cancelled
};

// =========================
// Function using enum
// =========================
string getColorName(Color c)
{
    switch (c)
    {
    case Red:
        return "Red";
    case Green:
        return "Green";
    case Blue:
        return "Blue";
    default:
        return "Unknown";
    }
}

// =========================
// Function using enum class
// =========================
string getStatusName(Status s)
{
    switch (s)
    {
    case Status::Pending:
        return "Pending";
    case Status::Shipped:
        return "Shipped";
    case Status::Delivered:
        return "Delivered";
    case Status::Cancelled:
        return "Cancelled";
    default:
        return "Unknown";
    }
}

// =========================
// Order System Example
// =========================
class Order
{
private:
    int id;
    Status status;

public:
    Order(int i) : id(i), status(Status::Pending) {}

    void setStatus(Status s)
    {
        status = s;
    }

    void print() const
    {
        cout << "Order ID: " << id << endl;
        cout << "Status: " << getStatusName(status) << endl;
    }
};

// =========================
// MAIN
// =========================
int main()
{
    // Basic enum usage
    Color c = Red;
    cout << "Color: " << getColorName(c) << endl;

    cout << "------------------" << endl;

    // Enum class usage
    Status s = Status::Shipped;
    cout << "Status: " << getStatusName(s) << endl;

    cout << "------------------" << endl;

    // Order system
    Order order1(101);
    order1.print();

    cout << "Updating status..." << endl;

    order1.setStatus(Status::Delivered);
    order1.print();

    cout << "------------------" << endl;

    // Loop through enum values manually
    Status allStatuses[] = {
        Status::Pending,
        Status::Shipped,
        Status::Delivered,
        Status::Cancelled};

    for (Status st : allStatuses)
    {
        cout << getStatusName(st) << endl;
    }

    return 0;
}