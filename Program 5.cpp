/*Define a class to represent a bank account. Include the following members:
Data members
1. Name of the depositor
2. Account number
3. Type of account
4. Balance amount in the account
Member functions
1. To assign initial values
2. To deposit an amount
3. To withdraw an amount after checking the balance
4. To display name and balance
Write a main program to test the program.
*/



#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string depositorName;
    long accountNumber;
    string accountType;
    double balance;

public:
    // Constructor to assign initial values
    BankAccount(string name, long accNumber, string accType, double bal)
        : depositorName(name), accountNumber(accNumber), accountType(accType), balance(bal) {}

    // Function to deposit an amount
    void deposit(double amount) {
        balance += amount;
    }

    // Function to withdraw an amount after checking the balance
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        } else {
            cout << "Insufficient balance to withdraw the amount." << endl;
            return false;
        }
    }

    // Function to display name and balance
    void display() const {
        cout << "Depositor Name: " << depositorName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    // Creating an object of BankAccount with initial values
    BankAccount account("Sam Bahadur", 123456789, "Savings", 50000.0);

    // Testing the deposit function
    account.deposit(10000.0);
    account.display();

    // Testing the withdraw function
    if (account.withdraw(22000.0)) {
        cout << "Withdrawal successful." << endl;
    }
    account.display();

    return 0;
}
