#include <iostream>
#include <vector>
using namespace std;

// Abstract Class
class Payment
{
protected:
    double amount;

public:
    Payment(double amt) : amount(amt) {}

    virtual void pay() const = 0;
    virtual void printReceipt() const = 0;

    virtual ~Payment() {}
};

// Credit Card Payment
class CreditCard : public Payment
{
private:
    string cardNumber;

public:
    CreditCard(double amt, string cardNum)
        : Payment(amt), cardNumber(cardNum) {}

    void pay() const override
    {
        cout << "Processing credit card payment...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " using Credit Card: "
             << "**** **** **** " << cardNumber.substr(cardNumber.length() - 4) << endl;
    }
};

// PayPal Payment
class PayPal : public Payment
{
private:
    string email;

public:
    PayPal(double amt, string mail)
        : Payment(amt), email(mail) {}

    void pay() const override
    {
        cout << "Processing PayPal payment...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " using PayPal account: " << email << endl;
    }
};

// Cash Payment
class Cash : public Payment
{
public:
    Cash(double amt) : Payment(amt) {}

    void pay() const override
    {
        cout << "Processing cash payment...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " in cash.\n";
    }
};

// Manager class
class PaymentProcessor
{
private:
    vector<Payment*> payments;

public:
    void addPayment(Payment* p)
    {
        payments.push_back(p);
    }

    void processAll()
    {
        for (const auto& p : payments)
        {
            p->pay();
            p->printReceipt();
            cout << "----------------------\n";
        }
    }

    ~PaymentProcessor()
    {
        for (auto p : payments)
        {
            delete p;
        }
    }
};

// Main
int main()
{
    PaymentProcessor processor;

    processor.addPayment(new CreditCard(150.75, "1234567812345678"));
    processor.addPayment(new PayPal(200.50, "user@example.com"));
    processor.addPayment(new Cash(50.00));

    processor.processAll();

    return 0;
}