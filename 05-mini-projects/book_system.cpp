#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;

public:
    Book()
    {
        title = "unknown";
        author = "unknown";
        price = 0;
    }

    Book(string s, string s2, double p)
    {
        title = s;
        author = s2;
        price = p;
    }

    // Copy Constructor
    Book(const Book& other)
    {
        title = other.title;
        author = other.author;
        price = other.price;
    }

    ~Book()
    {
        cout << "Book destroyed: " << title << endl;
    }

    // Getters
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }

    // Setter
    void setPrice(double p)
    {
        if (p >= 0)
            price = p;
    }

    void applyDiscount(double percent)
    {
        price -= price * (percent / 100);
    }

    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    // Operator +
    Book operator+(const Book& other)
    {
        Book result;
        result.title = this->title + " & " + other.title;
        result.author = this->author + " & " + other.author;
        result.price = this->price + other.price;
        return result;
    }

    // Operator ==
    friend bool operator==(const Book& ob1, const Book& ob2)
    {
        return (ob1.title == ob2.title &&
                ob1.author == ob2.author &&
                ob1.price == ob2.price);
    }

    // Operator <<
    friend ostream& operator<<(ostream& out, const Book& b)
    {
        out << "Title: " << b.title << "\n";
        out << "Author: " << b.author << "\n";
        out << "Price: " << b.price << "\n";
        return out;
    }
};

int main()
{
    Book b1("A", "X", 100);
    Book b2("B", "Y", 200);

    Book b3 = b1 + b2;

    cout << b3 << endl;

    if (b1 == b2)
        cout << "Equal\n";
    else
        cout << "Not Equal\n";

    b3.applyDiscount(10);
    cout << "After discount:\n" << b3;

    return 0;
}