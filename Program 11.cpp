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
