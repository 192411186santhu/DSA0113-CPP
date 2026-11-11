#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    string accountNumber;
    long long balance;
    double transactions[10]{};
    int count = 0;
    void record(double amount); // private helper
public:
    SavingsAccount(const string& number, long long opening)
        : accountNumber(number), balance(opening) {}
    void deposit(long long amount);
    void withdraw(long long amount);
    void miniStatement() const;
    long long getBalance() const { return balance; } // inline member
};

void SavingsAccount::record(double amount) {
    if (count < 10) transactions[count++] = amount;
    else {
        for (int i = 1; i < 10; ++i) transactions[i - 1] = transactions[i];
        transactions[9] = amount;
    }
}
void SavingsAccount::deposit(long long amount) {
    if (amount <= 0) return;
    balance += amount;
    record(static_cast<double>(amount));
}
void SavingsAccount::withdraw(long long amount) {
    if (amount <= 0 || amount > balance) return;
    balance -= amount;
    record(-static_cast<double>(amount));
}
void SavingsAccount::miniStatement() const {
    cout << "Account: " << accountNumber << "\nBalance: " << balance
         << "\nTransactions (oldest to newest):\n";
    for (int i = 0; i < count; ++i) cout << transactions[i] << '\n';
}
int main() {
    SavingsAccount a("SA1001", 5000);
    a.deposit(1000); a.withdraw(500); a.deposit(250);
    a.miniStatement();
}