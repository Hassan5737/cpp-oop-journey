#include <iostream>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
    string ownerName;
    int accountNumber;
    double balance;

    static int accountsCount;

public:

    // Default Constructor
    BankAccount()
        : ownerName("Unknown"), accountNumber(0), balance(0)
    {
        accountsCount++;
    }

    // Parameterized Constructor
    BankAccount(string name, int number, double money)
    {
        ownerName = name;

        if (number > 0)
            accountNumber = number;
        else
            accountNumber = 0;

        if (money >= 0)
            balance = money;
        else
            balance = 0;

        accountsCount++;
    }

    // Copy Constructor
    BankAccount(const BankAccount& other)
    {
        ownerName = other.ownerName;
        accountNumber = other.accountNumber;
        balance = other.balance;

        accountsCount++;
    }

    // =========================
    // Setters
    // =========================

    void setOwnerName(string name)
    {
        if (!name.empty())
            ownerName = name;
    }

    void setAccountNumber(int number)
    {
        if (number > 0)
            accountNumber = number;
        else
            cout << "Invalid account number\n";
    }

    // =========================
    // Banking Operations
    // =========================

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid deposit amount\n";
            return;
        }

        balance += amount;

        cout << amount
             << " deposited successfully\n";
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            cout << "Invalid withdraw amount\n";
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance\n";
            return;
        }

        balance -= amount;

        cout << amount
             << " withdrawn successfully\n";
    }

    // =========================
    // Getters
    // =========================

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

    // =========================
    // Utility Functions
    // =========================

    void print() const
    {
        cout << "\n============================\n";

        cout << left << setw(18)
             << "Owner Name:"
             << ownerName << endl;

        cout << left << setw(18)
             << "Account Number:"
             << accountNumber << endl;

        cout << left << setw(18)
             << "Balance:"
             << balance << endl;

        cout << "============================\n";
    }

    bool isRich() const
    {
        return balance >= 10000;
    }

    // =========================
    // Static Function
    // =========================

    static int getAccountsCount()
    {
        return accountsCount;
    }

    // =========================
    // Operator Overloading
    // =========================

    bool operator==(const BankAccount& other) const
    {
        return accountNumber == other.accountNumber;
    }

    bool operator>(const BankAccount& other) const
    {
        return balance > other.balance;
    }

    BankAccount operator+(const BankAccount& other) const
    {
        BankAccount temp;

        temp.ownerName =
            ownerName + " & " + other.ownerName;

        temp.accountNumber = 9999;

        temp.balance = balance + other.balance;

        return temp;
    }

    // =========================
    // Destructor
    // =========================

    ~BankAccount()
    {
        cout << "Account destroyed for: "
             << ownerName << endl;
    }
};

// Static Variable Definition
int BankAccount::accountsCount = 0;

// ==========================================
// Main
// ==========================================

int main()
{
    BankAccount acc1("Hassan", 101, 5000);
    BankAccount acc2("Ali", 102, 15000);

    cout << "\n===== Account 1 =====";
    acc1.print();

    cout << "\n===== Deposit =====\n";
    acc1.deposit(3000);

    cout << "\n===== Withdraw =====\n";
    acc1.withdraw(2000);

    cout << "\n===== Updated Account =====";
    acc1.print();

    cout << "\n===== Rich Check =====\n";

    if (acc2.isRich())
        cout << acc2.getOwnerName()
             << " is a rich client.\n";

    cout << "\n===== Operator + =====\n";

    BankAccount merged = acc1 + acc2;

    merged.print();

    cout << "\n===== Operator > =====\n";

    if (acc2 > acc1)
        cout << acc2.getOwnerName()
             << " has more balance.\n";

    cout << "\n===== Operator == =====\n";

    if (acc1 == acc2)
        cout << "Same Accounts\n";
    else
        cout << "Different Accounts\n";

    cout << "\n===== Total Accounts =====\n";

    cout << BankAccount::getAccountsCount()
         << " objects created.\n";

    return 0;
}