#include <iostream>

enum class Zone { Inner, Middle, Outer };
constexpr long long BASE_PAISE[] = {1000, 2000, 3000};
constexpr int PEAK_PERCENT = 20;
constexpr long long MIN_REMAINING_PAISE = 5000;

class FarePolicy {
public:
    static bool isPeak(int hour, int minute) {
        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) return false;
        const int time = hour * 60 + minute;
        return (time >= 480 && time < 600) ||
               (time >= 1020 && time < 1200);
    }
    static long long calculate(Zone zone, int hour, int minute) {
        const int index = static_cast<int>(zone);
        if (index < 0 || index >= 3 || hour < 0 || hour > 23 ||
            minute < 0 || minute > 59) return -1;
        long long amount = BASE_PAISE[index];
        if (isPeak(hour, minute))
            amount += (amount * PEAK_PERCENT + 50) / 100;
        return amount;
    }
};

class SmartCard {
    long long balance_;
public:
    explicit SmartCard(long long initial) : balance_(initial) {}
    bool travel(long long fare) {
        if (fare < 0 || balance_ - fare < MIN_REMAINING_PAISE) return false;
        balance_ -= fare;
        return true;
    }
    long long balance() const { return balance_; }
};

int main() {
    SmartCard card(10000);
    const long long amount = FarePolicy::calculate(Zone::Outer, 9, 0);
    std::cout << "Calculated fare: " << amount << " paise\n";
    std::cout << (card.travel(amount) ? "Accepted" : "Denied") << '\n';
    std::cout << "Remaining balance: " << card.balance() << " paise\n";
}
