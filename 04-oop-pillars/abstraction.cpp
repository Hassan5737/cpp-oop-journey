#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
using namespace std;

// ================= Exception =================
class PaymentException : public exception
{
private:
    string message;

public:
    PaymentException(const string& msg) : message(msg) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

// ================= Abstract Class =================
class Payment
{
protected:
    double amount;

public:
    Payment(double amt)
    {
        if (amt <= 0)
            throw PaymentException("Invalid payment amount!");

        amount = amt;
    }

    virtual void pay() const = 0;
    virtual void printReceipt() const = 0;
    virtual string getType() const = 0;

    virtual ~Payment() {}
};

// ================= Credit Card =================
class CreditCard : public Payment
{
private:
    string cardNumber;

public:
    CreditCard(double amt, const string& cardNum)
        : Payment(amt)
    {
        if (cardNum.length() < 4)
            throw PaymentException("Invalid card number!");

        cardNumber = cardNum;
    }

    void pay() const override
    {
        cout << "[CreditCard] Payment processing...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " using Credit Card ****"
             << cardNumber.substr(cardNumber.length() - 4) << endl;
    }

    string getType() const override
    {
        return "CreditCard";
    }
};

// ================= PayPal =================
class PayPal : public Payment
{
private:
    string email;

public:
    PayPal(double amt, const string& mail)
        : Payment(amt)
    {
        if (mail.find('@') == string::npos)
            throw PaymentException("Invalid email!");

        email = mail;
    }

    void pay() const override
    {
        cout << "[PayPal] Payment processing...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " using PayPal: " << email << endl;
    }

    string getType() const override
    {
        return "PayPal";
    }
};

// ================= Cash =================
class Cash : public Payment
{
public:
    Cash(double amt) : Payment(amt) {}

    void pay() const override
    {
        cout << "[Cash] Payment processing...\n";
    }

    void printReceipt() const override
    {
        cout << "Paid $" << amount << " in cash\n";
    }

    string getType() const override
    {
        return "Cash";
    }
};

// ================= Factory =================
class PaymentFactory
{
public:
    static unique_ptr<Payment> createPayment(int choice)
    {
        double amount;
        cout << "Enter amount: ";
        cin >> amount;

        if (choice == 1)
        {
            string card;
            cout << "Enter card number: ";
            cin >> card;
            return make_unique<CreditCard>(amount, card);
        }
        else if (choice == 2)
        {
            string email;
            cout << "Enter email: ";
            cin >> email;
            return make_unique<PayPal>(amount, email);
        }
        else if (choice == 3)
        {
            return make_unique<Cash>(amount);
        }

        throw PaymentException("Invalid payment type!");
    }
};

// ================= Logger =================
class Logger
{
public:
    static void log(const string& msg)
    {
        cout << "[LOG]: " << msg << endl;
    }
};

// ================= Transaction =================
class Transaction
{
private:
    unique_ptr<Payment> payment;

public:
    Transaction(unique_ptr<Payment> p)
        : payment(move(p)) {}

    void execute()
    {
        try
        {
            payment->pay();
            payment->printReceipt();
            Logger::log("Transaction success: " + payment->getType());
        }
        catch (const exception& e)
        {
            Logger::log(string("Transaction failed: ") + e.what());
        }
    }
};

// ================= Manager =================
class PaymentProcessor
{
private:
    vector<unique_ptr<Transaction>> transactions;

public:
    void addTransaction(unique_ptr<Transaction> t)
    {
        transactions.push_back(move(t));
    }

    void processAll()
    {
        for (auto& t : transactions)
        {
            t->execute();
            cout << "------------------\n";
        }
    }
};

// ================= Main =================
int main()
{
    PaymentProcessor processor;

    int choice;
    cout << "1. Credit Card\n2. PayPal\n3. Cash\nChoose: ";
    cin >> choice;

    try
    {
        auto payment = PaymentFactory::createPayment(choice);
        auto transaction = make_unique<Transaction>(move(payment));

        processor.addTransaction(move(transaction));
        processor.processAll();
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}