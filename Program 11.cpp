/*  Assume that a bank maintains two kinds of accounts for customers, one called as savings account and the 
other as current account. The savings account provides compound interest and withdrawal facilities but no 
cheque book facility. The current account provides cheque book facility but no interest. Current account 
holders should also maintain a minimum balance and if the balance falls below this level, a service chargeis imposed. Create a class account that stores customer name, account number and type of account. From 
this derive the classes curacct and savacct to make them more specific to their requirements. Include 
necessary member functions in order to achieve the following tasks: 
a. Accept deposit from a costumer and update the balance.
b. Display the balance
c. Compute and deposit interest.
d. Permit withdrawal and update the balance.
e. Check for the minimum balance, impose penalty, necessary and update balance.*/




#include <iostream>
#include <string>

// Base class
class Account {
protected:
    std::string customerName;
    long accountNumber;
    double balance;
    std::string accountType;

public:
    Account(std::string name, long acctNumber, std::string acctType)
        : customerName(name), accountNumber(acctNumber), accountType(acctType), balance(0) {}

    void deposit(double amount) {
        balance += amount;
    }

    void displayBalance() const {
        std::cout << "Balance: $" << balance << std::endl;
    }

    virtual void computeInterest() {}
    virtual void withdraw(double amount) {}
    virtual void checkMinimumBalance() {}
};

// Derived class for Savings Account
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(std::string name, long acctNumber, double rate)
        : Account(name, acctNumber, "Savings"), interestRate(rate) {}

    void computeInterest() override {
        double interest = balance * interestRate / 100;
        std::cout << "Interest: $" << interest << std::endl;
        deposit(interest);
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }
};

// Derived class for Current Account
class CurrentAccount : public Account {
private:
    double minimumBalance;
    double serviceCharge;

public:
    CurrentAccount(std::string name, long acctNumber, double minBalance, double charge)
        : Account(name, acctNumber, "Current"), minimumBalance(minBalance), serviceCharge(charge) {}

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            checkMinimumBalance();
        } else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }

    void checkMinimumBalance() override {
        if (balance < minimumBalance) {
            std::cout << "Balance below minimum. Service charge applied." << std::endl;
            balance -= serviceCharge;
        }
    }
};

int main() {
    SavingsAccount savAcc("Sam ahadur", 123456789, 5.0); // 5% interest rate
    CurrentAccount curAcc("Veer Savarker", 987654321, 500.0, 25.0); // $500 min balance, $25 service charge

    // Test Savings Account
    savAcc.deposit(1000);
    savAcc.displayBalance();
    savAcc.computeInterest();
    savAcc.displayBalance();
    savAcc.withdraw(200);
    savAcc.displayBalance();

    // Test Current Account
    curAcc.deposit(1000);
    curAcc.displayBalance();
    curAcc.withdraw(600);
    curAcc.displayBalance();
    curAcc.withdraw(400); // Should trigger service charge
    curAcc.displayBalance();

    return 0;
}
