#include <iostream>
using namespace std;

class Book
{
private:
    string title;
    string author;
    double price;

    static int bookCount; 

public:
   
    Book()
        : title("unknown"), author("unknown"), price(0.0)
    {
        bookCount++;
    }

   
    Book(string t, string a, double p)
        : title(t), author(a), price(p >= 0 ? p : 0)
    {
        bookCount++;
    }

    
    Book(const Book& other)
        : title(other.title), author(other.author), price(other.price)
    {
        bookCount++;
    }


    ~Book()
    {
        bookCount--;
    }

    
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    double getPrice() const { return price; }

    static int getBookCount()
    {
        return bookCount;
    }

    void setPrice(double p)
    {
        if (p >= 0)
            price = p;
    }


    void applyDiscount(double percent)
    {
        if (percent >= 0 && percent <= 100)
            price -= price * (percent / 100);
    }

    double getPriceWithTax(double taxPercent) const
    {
        return price + price * (taxPercent / 100);
    }


   
    Book operator+(const Book& other) const
    {
        return Book(
            title + " & " + other.title,
            author + " & " + other.author,
            price + other.price
        );
    }

  
    Book& operator+=(const Book& other)
    {
        title += " & " + other.title;
        author += " & " + other.author;
        price += other.price;
        return *this;
    }


    bool operator==(const Book& other) const
    {
        return (title == other.title &&
                author == other.author &&
                price == other.price);
    }

 
    bool operator<(const Book& other) const
    {
        return price < other.price;
    }

    
    friend ostream& operator<<(ostream& out, const Book& b)
    {
        out << "Title : " << b.title << "\n";
        out << "Author: " << b.author << "\n";
        out << "Price : " << b.price << "\n";
        return out;
    }


    Book* clone() const
    {
        return new Book(*this);
    }
};


int Book::bookCount = 0;


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

    cout << "\nBooks count: " << Book::getBookCount() << endl;

    // +=
    b1 += b2;
    cout << "\nAfter +=:\n" << b1;

    // Tax
    cout << "\nPrice with tax: " << b1.getPriceWithTax(14) << endl;

    // Clone
    Book* copy = b1.clone();
    cout << "\nCloned Book:\n" << *copy;

    delete copy;

    return 0;
}