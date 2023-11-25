#include <iostream>
#include <iomanip>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(const std::string &number, const std::string &holder, double initialBalance)
            : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

    virtual void displayDetails() const {
        std::string accountType = getAccountType();
        std::cout << "Account Details for " << accountType << " (ID: " << accountNumber << "):\n"
                  << "   Holder: " << accountHolder << "\n"
                  << "   Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }

    virtual std::string getAccountType() const {
        return "Account";
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "Withdrawal failed: Insufficient funds\n";
        }
    }

    virtual void transfer(Account &destination, double amount) {
        if (balance >= amount) {
            withdraw(amount);
            destination.deposit(amount);
        } else {
            std::cout << "Transfer failed: Insufficient funds\n";
        }
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(const std::string &number, const std::string &holder, double initialBalance, double rate)
            : Account(number, holder, initialBalance), interestRate(rate) {}

    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Interest Rate: " << std::fixed << std::setprecision(2) << (interestRate * 100) << "%\n";
    }

    std::string getAccountType() const override {
        return "Savings Account";
    }

    void deposit(double amount) override {
        Account::deposit(amount);
    }

    void withdraw(double amount) override {
        if (balance - amount >= 100) {  // Minimum balance of $100
            Account::withdraw(amount);
        } else {
            std::cout << "Withdrawal failed: Minimum balance not maintained\n";
        }
    }
};

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    CurrentAccount(const std::string &number, const std::string &holder, double initialBalance, double limit)
            : Account(number, holder, initialBalance), overdraftLimit(limit) {}

    void displayDetails() const override {
        Account::displayDetails();
        std::cout << "   Overdraft Limit: $" << std::fixed << std::setprecision(2) << overdraftLimit << "\n";
    }

    std::string getAccountType() const override {
        return "Current Account";
    }

    void deposit(double amount) override {
        Account::deposit(amount);
    }

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {  // Allowing overdraft up to the limit
            Account::withdraw(amount);
        } else {
            std::cout << "Withdrawal failed: Exceeds overdraft limit\n";
        }
    }
};

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    savings.displayDetails();
    current.displayDetails();

    std::cout << "\nAccount Details after deposit and withdrawal:\n";

    savings.deposit(500);
    current.withdraw(1000);

    savings.displayDetails();
    current.displayDetails();

    std::cout << "\nAccount Details after transfer:\n";

    savings.transfer(current, 300); // Transfer 300 from savings to current

    savings.displayDetails();
    current.displayDetails();

    return 0;
}
