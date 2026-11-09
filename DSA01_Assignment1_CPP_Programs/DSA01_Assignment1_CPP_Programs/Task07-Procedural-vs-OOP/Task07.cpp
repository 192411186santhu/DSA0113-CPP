#include <iostream>

bool proceduralCanTravel(long long balance, long long fare) {
    return fare >= 0 && balance - fare >= 5000;
}
bool proceduralDeduct(long long& balance, long long fare) {
    if (!proceduralCanTravel(balance, fare)) return false;
    balance -= fare;
    return true;
}

class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long balance) : balance_(balance) {}
    bool canTravel(long long fare) const {
        return fare >= 0 && balance_ - fare >= 5000;
    }
    bool deduct(long long fare) {
        if (!canTravel(fare)) return false;
        balance_ -= fare;
        return true;
    }
    long long balance() const { return balance_; }
};

int main() {
    long long proceduralBalance = 10000;
    SmartCard card(10000);
    const long long fare = 2400;

    std::cout << "Procedural payment: "
              << (proceduralDeduct(proceduralBalance, fare) ? "Accepted" : "Denied")
              << ", balance=" << proceduralBalance << " paise\n";
    std::cout << "OOP payment: "
              << (card.deduct(fare) ? "Accepted" : "Denied")
              << ", balance=" << card.balance() << " paise\n";
}
