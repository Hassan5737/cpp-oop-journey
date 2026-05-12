#include <iostream>
using namespace std;

// =====================================
// Example 1
// Multiple Inheritance with protected
// =====================================

// Base Class 1
class Animal
{
protected:
    string name;

public:

    Animal()
    {
        name = "Unknown";
        cout << "Animal Default Constructor Called" << endl;
    }

    Animal(string n)
    {
        name = n;
        cout << "Animal Parameterized Constructor Called" << endl;
    }

    void eat()
    {
        cout << name << " is eating" << endl;
    }
};

// Base Class 2
class Pet
{
protected:
    int age;

public:

    Pet()
    {
        age = 0;
        cout << "Pet Default Constructor Called" << endl;
    }

    Pet(int a)
    {
        age = a;
        cout << "Pet Parameterized Constructor Called" << endl;
    }

    void showAge()
    {
        cout << "Age: " << age << endl;
    }
};

// Derived Class
class Dog : public Animal, public Pet
{
public:

    Dog() : Animal(), Pet()
    {
        cout << "Dog Default Constructor Called" << endl;
    }

    Dog(string n, int a) : Animal(n), Pet(a)
    {
        cout << "Dog Parameterized Constructor Called" << endl;
    }

    void bark()
    {
        cout << name << " says: Woof Woof" << endl;
    }

    void dogInfo()
    {
        cout << "Dog Name: " << name << endl;
        cout << "Dog Age: " << age << endl;
    }
};

// =====================================
// Example 2
// =====================================

// Base Class 1
class Engine
{
protected:
    int horsePower;

public:

    Engine()
    {
        horsePower = 100;
    }

    Engine(int hp)
    {
        horsePower = hp;
    }

    void startEngine()
    {
        cout << "Engine Started" << endl;
    }
};

// Base Class 2
class MusicSystem
{
protected:
    string musicBrand;

public:

    MusicSystem()
    {
        musicBrand = "Unknown";
    }

    MusicSystem(string brand)
    {
        musicBrand = brand;
    }

    void playMusic()
    {
        cout << "Music is Playing" << endl;
    }
};

// Derived Class
class Car : public Engine, public MusicSystem
{
public:

    Car() : Engine(), MusicSystem()
    {
    }

    Car(int hp, string brand)
        : Engine(hp), MusicSystem(brand)
    {
    }

    void drive()
    {
        cout << "Car is Driving" << endl;
    }

    void showCarInfo()
    {
        cout << "Horse Power: " << horsePower << endl;
        cout << "Music System Brand: " << musicBrand << endl;
    }
};

// =====================================
// Example 3
// =====================================

// Base Class 1
class Father
{
protected:
    string fatherTalent;

public:

    Father()
    {
        fatherTalent = "Fishing";
    }

    void fatherSkill()
    {
        cout << "Father knows " << fatherTalent << endl;
    }
};

// Base Class 2
class Mother
{
protected:
    string motherTalent;

public:

    Mother()
    {
        motherTalent = "Cooking";
    }

    void motherSkill()
    {
        cout << "Mother knows " << motherTalent << endl;
    }
};

// Derived Class
class Child : public Father, public Mother
{
protected:
    string childTalent;

public:

    Child()
    {
        childTalent = "Programming";
    }

    void childSkill()
    {
        cout << "Child knows " << childTalent << endl;
    }

    void showAllTalents()
    {
        cout << "Father Talent: " << fatherTalent << endl;
        cout << "Mother Talent: " << motherTalent << endl;
        cout << "Child Talent: " << childTalent << endl;
    }
};

// =====================================
// Main Function
// =====================================

int main()
{
    // =====================================
    // Example 1
    // =====================================

    cout << "========== Dog Example ==========\n";

    Dog dog1("Max", 5);

    dog1.eat();
    dog1.showAge();
    dog1.bark();
    dog1.dogInfo();

    cout << endl;

    // =====================================
    // Example 2
    // =====================================

    cout << "========== Car Example ==========\n";

    Car car1(450, "Sony");

    car1.startEngine();
    car1.playMusic();
    car1.drive();
    car1.showCarInfo();

    cout << endl;

    // =====================================
    // Example 3
    // =====================================

    cout << "========== Child Example ==========\n";

    Child c1;

    c1.fatherSkill();
    c1.motherSkill();
    c1.childSkill();
    c1.showAllTalents();

    return 0;
}