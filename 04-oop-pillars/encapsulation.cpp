#include <iostream>
using namespace std;

// ==========================================
// Encapsulation Example in C++
// ==========================================

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance;

public:

    // Default Constructor
    BankAccount()
    {
        ownerName = "Unknown";
        accountNumber = 0;
        balance = 0;
    }

    // Parameterized Constructor
    BankAccount(string name, int number, double money)
    {
        ownerName = name;
        accountNumber = number;
        balance = money;
    }

    // Setters
    void setOwnerName(string name)
    {
        ownerName = name;
    }

    void setAccountNumber(int number)
    {
        if (number > 0)
        {
            accountNumber = number;
        }
        else
        {
            cout << "Invalid account number\n";
        }
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " deposited successfully\n";
        }
        else
        {
            cout << "Invalid deposit amount\n";
        }
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdraw amount\n";
        }
        else if (amount > balance)
        {
            cout << "Not enough balance\n";
        }
        else
        {
            balance -= amount;
            cout << amount << " withdrawn successfully\n";
        }
    }

    // Getters
    string getOwnerName() const
    {
        return ownerName;
    }

    int getAccountNumber() const
    {
        return accountNumber;
    }

    double getBalance() const
    {
        return balance;
    }

    // Print Function
    void print() const
    {
        cout << "Owner Name: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Operator Overloading
    bool operator==(const BankAccount& other) const
    {
        return accountNumber == other.accountNumber;
    }

    BankAccount operator+(const BankAccount& other) const
    {
        BankAccount result;

        result.ownerName = ownerName + " & " + other.ownerName;
        result.accountNumber = 9999;
        result.balance = balance + other.balance;

        return result;
    }

    // Destructor
    ~BankAccount()
    {
        cout << "Account destroyed: " << ownerName << endl;
    }
};

// ==========================================
// Main
// ==========================================

int main()
{
    BankAccount acc1("Hassan", 101, 5000);
    BankAccount acc2("Ali", 102, 3000);

    cout << "===== Account 1 =====\n";
    acc1.print();

    cout << "\n===== Deposit =====\n";
    acc1.deposit(2000);

    cout << "\n===== Withdraw =====\n";
    acc1.withdraw(1000);

    cout << "\n===== Updated Account =====\n";
    acc1.print();

    cout << "\n===== Getters =====\n";
    cout << acc1.getOwnerName() << endl;
    cout << acc1.getBalance() << endl;

    cout << "\n===== Operator + =====\n";

    BankAccount acc3 = acc1 + acc2;

    acc3.print();

    cout << "\n===== Operator == =====\n";

    if (acc1 == acc2)
    {
        cout << "Same Account\n";
    }
    else
    {
        cout << "Different Accounts\n";
    }

    return 0;
}