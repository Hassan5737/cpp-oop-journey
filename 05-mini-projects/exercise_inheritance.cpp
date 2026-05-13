#include <iostream>
using namespace std;

// =====================================
// Base Class
// =====================================
class Animal
{
public:

    // Virtual Function
    virtual void makeSound()
    {
        cout << "Animal makes a sound" << endl;
    }
};