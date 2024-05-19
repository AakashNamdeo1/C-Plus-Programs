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

    // Additional methods can be added here
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
