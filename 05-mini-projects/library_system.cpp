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

    bool operator==(const book& other)
    {
        return (this->title == other.title && this->author == other.author);
    }

    book operator+(const book& other)
    {
        book result;

        result.price = this->price + other.price;
        result.title = this->title + " & " + other.title;
        result.author = this->author + " & " + other.author;

        return result;
    }

    void print() const
    {
        cout << "Book title: " << title << endl;
        cout << "Book author: " << author << endl;
        cout << "Book price: " << price << endl;
    }

    ~book() {}
};