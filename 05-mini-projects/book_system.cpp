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
        this->title = s;
        this->author = s2;
        this->price = p;
    }

    ~Book()
    {
        cout << "Book destroyed: " << title << endl;
    }

    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

   Book operator+(const Book& other)
{
    Book result;

    result.title = this->title;     
    result.author = this->author;
    result.price = this->price + other.price;

    return result;
}

   friend bool operator==(const Book& ob1, const Book& ob2)
{
    return (ob1.title == ob2.title && ob1.author == ob2.author);
}
};

int main()
{
 Book b1("A", "X", 100);
 Book b2("B", "Y", 200);

Book b3 = b1 + b2;

if (b1 == b2)
    cout << "Equal\n";
else
    cout << "Not Equal\n";

}