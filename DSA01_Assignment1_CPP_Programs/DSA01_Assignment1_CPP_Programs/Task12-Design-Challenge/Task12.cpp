#include <iostream>

enum class Zone { Inner, Middle, Outer, Airport, Count };
constexpr int ZONE_COUNT = static_cast<int>(Zone::Count);
constexpr long long BASE_PAISE[ZONE_COUNT] = {1000, 2000, 3000, 6000};
constexpr int CONCESSION_PERCENT = 50;
constexpr int WEEKEND_DISCOUNT_PERCENT = 10;
constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_REMAINING_PAISE = 5000;

struct Journey {
    Zone zone;
    int hour;
    int minute;
    int weekday; // 0=Monday ... 5=Saturday, 6=Sunday
    int month;   // simplified month identifier for this demonstration
    bool concession;
};

bool isPeak(int hour, int minute) {
    const int t = hour * 60 + minute;
    return (t >= 480 && t < 600) || (t >= 1020 && t < 1200);
}
long long percentOf(long long amount, int percent) {
    return (amount * percent + 50) / 100;
}
long long calculateFare(const Journey& j) {
    const int index = static_cast<int>(j.zone);
    if (index < 0 || index >= ZONE_COUNT || j.hour < 0 || j.hour > 23 ||
        j.minute < 0 || j.minute > 59 || j.weekday < 0 || j.weekday > 6)
        return -1;
    long long amount = BASE_PAISE[index];
    if (j.concession)
        amount -= percentOf(amount, CONCESSION_PERCENT);
    if (j.weekday == 5 || j.weekday == 6)
        amount -= percentOf(amount, WEEKEND_DISCOUNT_PERCENT);
    else if (isPeak(j.hour, j.minute))
        amount += percentOf(amount, PEAK_SURCHARGE_PERCENT);
    return amount;
}

class MonthlyPass {
    unsigned zoneMask_;
    int validMonth_;
public:
    MonthlyPass(Zone first, Zone second, int month)
        : zoneMask_((1u << static_cast<int>(first)) |
                    (1u << static_cast<int>(second))),
          validMonth_(month) {}
    bool covers(const Journey& journey) const {
        const int index = static_cast<int>(journey.zone);
        return index >= 0 && index < ZONE_COUNT &&
               journey.month == validMonth_ &&
               (zoneMask_ & (1u << index)) != 0;
    }
};

class SmartCard {
    long long balance_;
    const MonthlyPass* pass_ = nullptr;
public:
    explicit SmartCard(long long balance) : balance_(balance) {}
    void attachPass(const MonthlyPass* pass) { pass_ = pass; }
    long long balance() const { return balance_; }
    bool travel(const Journey& journey) {
        if (pass_ != nullptr && pass_->covers(journey)) return true;
        const long long amount = calculateFare(journey);
        if (amount < 0 || balance_ - amount < MIN_REMAINING_PAISE)
            return false;
        balance_ -= amount;
        return true;
    }
};

int main() {
    const MonthlyPass pass(Zone::Inner, Zone::Middle, 11);
    SmartCard card(10000);
    card.attachPass(&pass);

    const Journey airportWeekendStudent{
        Zone::Airport, 9, 0, 5, 11, true
    };
    const Journey coveredMiddle{
        Zone::Middle, 10, 0, 1, 11, false
    };

    std::cout << "Airport Saturday student fare: "
              << calculateFare(airportWeekendStudent) << " paise\n";
    std::cout << "Airport journey: "
              << (card.travel(airportWeekendStudent) ? "Accepted" : "Denied")
              << '\n';
    std::cout << "Covered Middle pass journey: "
              << (card.travel(coveredMiddle) ? "Accepted (pass)" : "Denied")
              << '\n';
    std::cout << "Remaining balance: " << card.balance() << " paise\n";
}
