/*
==========================================================
                Movie Management System
==========================================================

Goal:
Build a complete OOP project that reviews all major
concepts learned so far.

==========================================================
1) Abstract Base Class
==========================================================

Create an abstract class:

Media

Protected:
---------
string title;
int year;

Public:
------
- Default Constructor
- Parameterized Constructor
- Virtual print() function
- Pure Virtual function:

    virtual double getRating() const = 0;

- Virtual Destructor

==========================================================
2) Derived Class: Movie
==========================================================

Inherits publicly from Media.

Private:
--------
string director;
double rating;

Public:
-------
- Default Constructor
- Parameterized Constructor
- Override print()
- Override getRating()

==========================================================
3) Derived Class: Series
==========================================================

Inherits publicly from Media.

Private:
--------
int seasons;
double rating;

Public:
-------
- Default Constructor
- Parameterized Constructor
- Override print()
- Override getRating()

==========================================================
4) Review Class
==========================================================

Represents user reviews.

Private:
--------
double* scores;
int size;

Public:
-------
- Default Constructor
- Parameterized Constructor

- Deep Copy Constructor

- Destructor

- double averageScore() const

- print()

==========================================================
5) Operator Overloading
==========================================================

Inside Review:

A) operator+

Combine two reviews into one.

Example:

Review r3 = r1 + r2;

----------------------------------------------------------

B) operator[]

Access a score by index.

Example:

cout << r1[0];

----------------------------------------------------------

C) operator==

Compare two Review objects.

==========================================================
6) Friend Function
==========================================================

Create friend function:

compareReviews()

Returns the Review with higher average.

==========================================================
7) Friend Class
==========================================================

Create class:

ReviewAnalyzer

Make it friend of Review.

Can access private scores directly.

Function:

showHighestScore()

==========================================================
8) Library Class
==========================================================

MovieLibrary

Private:
--------
Media** items;
int size;

Public:
-------
- Default Constructor
- Parameterized Constructor

- Destructor

- printAll()

- averageRating()

==========================================================
9) Polymorphism
==========================================================

Store:

Movie objects
Series objects

Inside:

Media* array

Example:

Media* p;

p = &movie;
p = &series;

==========================================================
10) Operator Overloading For Library
==========================================================

A) operator+

Merge two libraries.

Example:

MovieLibrary lib3 = lib1 + lib2;

----------------------------------------------------------

B) operator[]

Access item by index.

Example:

lib[0]->print();

----------------------------------------------------------

C) operator==

Compare two libraries.

==========================================================
11) Static Member
==========================================================

Inside Media:

static int mediaCount;

Tracks total number of created objects.

Create:

static void showCount();

==========================================================
12) Const Functions
==========================================================

Use const whenever appropriate.

Examples:

print() const
getRating() const
averageScore() const

==========================================================
13) Main Function
==========================================================

Create:

- Movies
- Series
- Reviews

Test:

- Deep Copy
- Polymorphism
- Friend Function
- Friend Class
- Operator+
- Operator[]
- Operator==
- Static Member

Print final results clearly.

==========================================================
Bonus Challenges (Optional)
==========================================================

[ ] Input operator >>
[ ] Output operator <<
[ ] Unary Operator
[ ] Enumeration Genre
[ ] Copy Assignment Operator

==========================================================
*/

#include<iostream>
using namespace std;

class Media
{
protected:
    string title;
    int year;

public:

    Media()
    {
        title = "Unknown";
        year = 0;
    }

    Media(string t, int y)
    {
        title = t;
        year = y;
    }

    virtual void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Year: " << year << endl;
    }

    virtual double getRating() const = 0;

    virtual ~Media() {}
};

class Movie : public Media
{
private:
    string director;
    double rating;

public:

    Movie()
        : Media()
    {
        director = "Unknown";
        rating = 0;
    }

    Movie(string t, int y, string d, double r)
        : Media(t, y)
    {
        director = d;
        rating = r;
    }

    void print() const override
    {
        Media::print();

        cout << "Director: " << director << endl;
        cout << "Rating: " << rating << endl;
    }

    double getRating() const override
    {
        return rating;
    }
};

class Series : public Media
{
    private:
        int seasons;
        double rating;
    public:
        Series()
            :Media()
            {
                seasons = 0;
                rating = 0;
            }
        Series(string t, int y, int s, double r)
            :Media(t,y)
            {
                seasons = s;
                rating = r;
            }
        void print() const override
        {
            Media::print();

            cout << "seasons: " << seasons << endl;
            cout << "rating: " << rating << endl;
        }

        double getRating() const override
        {
            return rating;
        }
};