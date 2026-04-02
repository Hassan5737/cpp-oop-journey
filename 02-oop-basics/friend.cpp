#include <iostream>
using namespace std;

class BankManager; // forward declaration

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNum, double bal)
    {
        ownerName = name;
        accountNumber = accNum;
        balance = bal;
    }

    // Deposit
    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit\n";
            return;
        }
        balance += amount;
    }

    // Withdraw
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Not enough balance\n";
            return;
        }
        balance -= amount;
    }

    void print() const
    {
        cout << "Owner: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Friend Function
    friend double getBalance(BankAccount acc);

    // Friend Class
    friend class BankManager;
};

// Friend Function
double getBalance(BankAccount acc)
{
    return acc.balance; // access private directly
}

// Class uses Friend access
class BankManager
{
public:
    void bonus(BankAccount &acc, double amount)
    {
        acc.balance += amount; // direct access 🔥
    }

    void resetAccount(BankAccount &acc)
    {
        acc.balance = 0;
    }
};

// Another class (normal usage)
class Transaction
{
private:
    double amount;

public:
    Transaction(double amt)
    {
        amount = amt;
    }

    void applyDeposit(BankAccount &acc)
    {
        acc.deposit(amount);
    }

    void applyWithdraw(BankAccount &acc)
    {
        acc.withdraw(amount);
    }
};

int main()
{
    BankAccount acc("Hassan", 12345, 1000);

    acc.print();

    cout << "\n--- Transaction ---\n";
    Transaction t1(500);
    t1.applyDeposit(acc);

    Transaction t2(200);
    t2.applyWithdraw(acc);

    acc.print();

    cout << "\nBalance (friend function): " << getBalance(acc) << endl;

    cout << "\n--- Manager تدخل 🔥 ---\n";
    BankManager manager;
    manager.bonus(acc, 1000); // add bonus
    acc.print();

    manager.resetAccount(acc); // reset account
    acc.print();

    return 0;
}