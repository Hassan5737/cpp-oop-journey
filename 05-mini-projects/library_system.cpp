#include<iostream>
using namespace std;

class book
{
private:
    string title;
    string author;
    double price;

public:
    book()
    {
        title = "unknown";
        author = "unknown";
        price = 0;
    }

    book(string s, string a, double p)
    {
        title = s;
        author = a;
        price = p;
    }

    bool operator==(const book& other) const
    {
        return (title == other.title && author == other.author);
    }

    book operator+(const book& other) const
    {
        book result;

        result.price = price + other.price;
        result.title = title + " & " + other.title;
        result.author = author + " & " + other.author;

        return result;
    }

    double getPrice() const
    {
        return price;
    }

    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    ~book() {}
};

class library
{
private:
    book* books;
    int size;

public:
    // Default constructor
    library()
    {
        books = nullptr;
        size = 0;
    }

    // Parameterized constructor (Deep Copy)
    library(book arr[], int s)
    {
        size = s;
        books = new book[size];

        for (int i = 0; i < size; i++)
        {
            books[i] = arr[i];
        }
    }

    // Copy Constructor (Deep Copy)
    library(const library& other)
    {
        size = other.size;
        books = new book[size];

        for (int i = 0; i < size; i++)
        {
            books[i] = other.books[i];
        }
    }

    // Destructor
    ~library()
    {
        delete[] books;
    }

    // Print all books
    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Book " << i + 1 << ":\n";
            books[i].print();
            cout << "--------\n";
        }
    }

    // operator[]
    book& operator[](int index)
    {
        return books[index];
    }

    // operator+
    library operator+(const library& other) const
    {
        library result;

        result.size = size + other.size;
        result.books = new book[result.size];

        // copy first library
        for (int i = 0; i < size; i++)
        {
            result.books[i] = books[i];
        }

        // copy second library
        for (int i = 0; i < other.size; i++)
        {
            result.books[i + size] = other.books[i];
        }

        return result;
    }

    // operator==
    bool operator==(const library& other) const
    {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++)
        {
            if (!(books[i] == other.books[i]))
                return false;
        }

        return true;
    }

    // total price
    double totalPrice() const
    {
        double sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += books[i].getPrice();
        }

        return sum;
    }
};

int main()
{
    book b1("A", "X", 100);
    book b2("B", "Y", 200);
    book b3("C", "Z", 300);

    book arr1[] = {b1, b2};
    book arr2[] = {b3};

    library l1(arr1, 2);
    library l2(arr2, 1);

    library l3 = l1 + l2;

    l3.print();

    cout << "First book:\n";
    l3[0].print();

    cout << "Total price: " << l3.totalPrice() << endl;

    return 0;
}