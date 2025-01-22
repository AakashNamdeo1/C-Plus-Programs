//Design a constructor for bank account class.



#include <iostream>
#include <string>

class BankAccount {
private:
    std::string ownerName;
    long accountNumber;
    double balance;

public:
    // Constructor with parameters to initialize the attributes
    BankAccount(const std::string &name, long acctNumber, double initialBalance) 
        : ownerName(name), accountNumber(acctNumber), balance(initialBalance) {
        std::cout << "BankAccount for " << ownerName << " with account number " 
                  << accountNumber << " created. Initial balance is $" 
                  << balance << std::endl;
    }

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
    BankAccount myAccount("Veer Savarkar ", 123456789, 100000.00);

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
